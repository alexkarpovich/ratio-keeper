#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include "appcore.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext * ctx = engine.rootContext();

    qmlRegisterType<AppCore>("AppCore", 1, 0, "AppCore");

    AppCore appCore;

    ctx->setContextProperty("appCore", &appCore);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
