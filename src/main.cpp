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
    qRegisterMetaType<NodesGraph>();
    qRegisterMetaType<NodesGraph*>("const NodesGraph*");
    qRegisterMetaType<NodeEnums::NodeType>("NodeEnums::NodeType");


    qmlRegisterUncreatableType<GlobalVariablesContainer>("vstApp",1,0,"GlobalVariablesContainer",
                                                         "Type cannot be created in QML");
    qmlRegisterType<GlobalVariable>("vstApp", 1,0, "GlobalVariable");
    qmlRegisterUncreatableType<NodesGraphContainer>("vstApp",1,0,"NodesGraphContainer",
                                                         "Type cannot be created in QML");
    qmlRegisterType<NodesGraph>("vstApp", 1,0, "NodesGraph");




    VisualScriptingThreadsApp vstApp;
    vstApp.gigaManager->nodesGraphContainer->addGraph();


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("threadManager",
                                vstApp.gigaManager->threadManager);
    engine.rootContext()->setContextProperty("globalVariablesContainer",
                                vstApp.gigaManager->globalVariablesContainer);
    engine.rootContext()->setContextProperty("nodesGraphContainer",
                                vstApp.gigaManager->nodesGraphContainer);
    engine.rootContext()->setContextProperty("nodeEnums",
                                new NodeEnums());


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
