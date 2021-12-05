#include <QGuiApplication>
#include <QQmlApplicationEngine>
<<<<<<< Updated upstream:cpp/main.cpp

=======
#include <QQmlContext>
#include "node.h"
>>>>>>> Stashed changes:src/main.cpp

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

    QQmlContext *context = new QQmlContext(engine.rootContext());


    context->setContextProperty("globalVariablesContainer",
                                qobject_cast <QObject*>(vstApp.gigaManager->globalVariablesContainer));


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
