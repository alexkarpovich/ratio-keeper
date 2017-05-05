#ifndef CUSTOMIZECORE_H
#define CUSTOMIZECORE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "appconfig.h"
#include "apputility.h"
#include "models/account.h"
#include "models/currency.h"
#include "models/user.h"
#include "models/expense_category.h"

/**
 * @brief The CustomizeCore class
 *
 * Provides functionality for customization state
 */
class CustomizeCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Currency* currency READ getCurrency WRITE setCurrency NOTIFY propChanged)
    Q_PROPERTY(User* user READ getUser WRITE setUser NOTIFY propChanged)

    AppConfig *config;
    User *_user;
    Currency *_currency;
    QList<ExpenseCategory *> _categoryList;
    QList<Account *> _accountList;

public:
    explicit CustomizeCore(QObject *parent = 0);

    Currency *getCurrency() const;
    void setCurrency(Currency *value);

    AppConfig *getConfig() const;
    void setConfig(AppConfig *value);

    User *getUser() const;
    void setUser(User *user);

    QList<ExpenseCategory *> getCategoryList() const;
    void setCategoryList(const QList<ExpenseCategory *> &value);

    QList<Account *> getAccountList() const;
    void setAccountList(const QList<Account *> &value);


signals:
    void propChanged();
public slots:
    QList<QObject *> getCategories();
    QList<QObject *> getAccouns();
    QList<QObject *> getCurrencyList();
    void addCategory(const QString &name, const QString &icon);
};

#endif // CUSTOMIZECORE_H
