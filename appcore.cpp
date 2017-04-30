#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include "appcore.h"

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    this->dataLocation = QStandardPaths::standardLocations(QStandardPaths::DataLocation)[0];
    this->config = new AppConfig();

    QDir dataDir(this->dataLocation);

    if (!dataDir.exists()) {
        dataDir.mkdir(this->dataLocation);
    }

    QMap<QString, QString> files;
    files["db.sqlite"] = this->dataLocation;

    this->copyFiles(files);
    this->initDataBase();
    this->initActuals();
}

void AppCore::copyFiles(QMap<QString, QString> files) {
    QString filename = "";
    QString distFolder = "";
    QMap<QString, QString>::const_iterator i = files.constBegin();

    while (i != files.constEnd()) {
        filename = i.key();
        distFolder = i.value();
        QFileInfo dataDirInfo(distFolder);

        if (!dataDirInfo.isWritable()) {
            qDebug() << "Have not premissions to write to " + distFolder;
            return;
        }
        QString filePath = distFolder + "/" + filename;
        QFileInfo fileInfo(filePath);

        if (!fileInfo.exists()) {
            QFile::copy(":/" + filename, filePath);
            QFile::setPermissions(filePath, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        }

        ++i;
    }
}

void AppCore::initDataBase() {
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(this->dataLocation + "/db.sqlite");

    if (!sdb.open()) {
        qDebug() << sdb.lastError().text();
    }
}

void AppCore::initActuals() {
    qDebug() << "AppCore::initActuals -";
    this->setState(State::START);

    User * user = User::getActiveUser();

    if (user) {
        this->setUser(user);
        this->setInstance(Instance::getByUserId(user->getId()));
    }

    if (this->hasActiveUser()) {
        this->setState(State::DASHBOARD);
    }
}

AppCore::State AppCore::getState() {
    qDebug() << "AppCore::getState -" + this->appState;
    return this->appState;
}

Instance * AppCore::getInstance() {
    qDebug() << "AppCore::getInstance -";

    return this->instance;
}

User * AppCore::getUser() {
    qDebug() << "AppCore::getUser -";

    return this->user;
}

QStringList AppCore::getCustomCategories() {
    qDebug() << "AppCore::getCustomCategories -";

    if (this->customCategories.size() == 0) {
        this->customCategories = this->getDefaultCategories();
    }

    return this->customCategories;
}

bool AppCore::hasActiveUser() {
    return this->user != NULL;
}

void AppCore::setState(State state) {
    qDebug() << "AppCore::setState " + state;
    if (this->appState != state) {
        this->appState = state;
        emit stateChanged(this->appState);

        qDebug() << "AppCore::stateChanged " + this->appState;
    }
}

void AppCore::setInstance(Instance * instance) {
    qDebug() << "AppCore::setInstance -" << instance->getId();

    this->instance = instance;
}

void AppCore::setUser(User * user) {
    qDebug() << "AppCore::setUser -" << user->getId();

    this->user = user;
}

Currency *AppCore::getCurrency() const
{
    return currency;
}

void AppCore::setCurrency(Currency *currency)
{
    this->currency = currency;
}

void AppCore::addCustomCategory(QString category) {
    qDebug() << "AppCore::addCustomCategory -" << category;

    this->customCategories.append(category);
}

QStringList AppCore::getDefaultCategories()
{
    qDebug() << "AppCore::getDefaultCategories -";

    return config->get("expense_categories");
}

QStringList AppCore::getDefaultAccounts()
{
    qDebug() << "AppCore::getDefaultAccounts -";

    return config->get("accounts");
}

void AppCore::configureInstance(QList<QString> selected) {
    qDebug() << selected;

    // Create user with temp name

    User * user = new User();
    user->setUsername(QDateTime::currentDateTime().toString());
    user->setActive(true);
    user->save();

    // Create instance

    Instance * instance = new Instance();
    instance->save();
    instance->addUser(user);

    // Set currency

    Currency * currency = Currency::getByNumber(config->get("currency", "default").toInt());
    this->setCurrency(currency);

    // Create accounts

    Account::createFromList(instance, user, currency, this->getDefaultAccounts());

    // Create expense categories from customize page
    ExpenseCategory::createFromList(instance, selected);

    this->setInstance(instance);
    this->setUser(user);
    this->setState(State::DASHBOARD);
}

QList<QObject*> AppCore::getCategoryList()
{
    qDebug() << "AppCore::getCategoryList -";
    QList<ExpenseCategory*> categories = ExpenseCategory::getByInstanceId(this->getInstance()->getId());
    QList<QObject*> categoryList;

    foreach (ExpenseCategory* ctg, categories) {
        categoryList.append(ctg);
    }

    return categoryList;
}

QList<QObject *> AppCore::getAccountList()
{
    qDebug() << "AppCore::getAccountList -";

    QList<Account*> accounts = Account::getByInstanceId(this->getInstance()->getId());
    QList<QObject*> accountList;

    foreach (Account* acc, accounts) {
        accountList.append(acc);
    }

    return accountList;
}

