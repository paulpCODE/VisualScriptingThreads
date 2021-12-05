#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "visualscriptingthreadsapp.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<GlobalVariablesContainer>("vstApp",1,0,"GlobalVariablesContainer",
                                                         "Type cannot be created in QML");
    qmlRegisterType<GlobalVariable>("vstApp", 1,0, "GlobalVariable");


    VisualScriptingThreadsApp vstApp ;


    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty("globalVariablesContainer",
                                vstApp.gigaManager->globalVariablesContainer);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
