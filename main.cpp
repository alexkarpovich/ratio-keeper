#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include "appcore.h"
#include "customizecore.h"
#include "models/account.h"
#include "models/expense_category.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext * ctx = engine.rootContext();

    qmlRegisterType<AppCore>("AppCore", 1, 0, "AppCore");
    qmlRegisterType<Account>("Model", 1, 0, "Account");
    qmlRegisterType<ExpenseCategory>("Model", 1, 0, "ExpenseCategory");

    AppCore * appCore = new AppCore();
    CustomizeCore * customizeCore = new CustomizeCore();

    appCore->setCustomizeCore(customizeCore);
    ctx->setContextProperty("appCore", appCore);
    ctx->setContextProperty("customizeCore", customizeCore);
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

    return app.exec();
}
