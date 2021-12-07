#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "visualscriptingthreadsapp.h"
#include "nodesgraphcontainer.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qRegisterMetaType<GlobalVariable>();
    qRegisterMetaType<GlobalVariable*>("const GlobalVariable*");

    qmlRegisterUncreatableType<GlobalVariablesContainer>("vstApp",1,0,"GlobalVariablesContainer",
                                                         "Type cannot be created in QML");
    qmlRegisterType<GlobalVariable>("vstApp", 1,0, "GlobalVariable");
    qmlRegisterUncreatableType<NodesGraphContainer>("vstApp",1,0,"NodesGraphContainer",
                                                         "Type cannot be created in QML");
    qmlRegisterType<NodesGraph>("vstApp", 1,0, "NodesGraph");

    //qRegisterMetaType<NodeEnums::NodeType>("NodeEnums::NodeType");



    VisualScriptingThreadsApp vstApp;


    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty("globalVariablesContainer",
                                vstApp.gigaManager->globalVariablesContainer);
    engine.rootContext()->setContextProperty("nodesGraphContainer",
                                vstApp.gigaManager->nodesGraphContainer);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
