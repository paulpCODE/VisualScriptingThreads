#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QVector>
#include <QThread>
#include <QStringList>
#include "threadworker.h"
#include "nodesgraphcontainer.h"
class ThreadManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList qstringlistThreadsModel READ qstringlistThreadsModel WRITE setQstringlistThreadsModel NOTIFY qstringlistThreadsModelChanged)

public:
    ThreadManager( NodesGraphContainer * nodesGraphContainer,GlobalVariablesContainer * gvcptr);

    const QStringList &qstringlistThreadsModel() const;
    void setQstringlistThreadsModel(const QStringList &newQstringlistThreadsModel);
signals:
    void qstringlistThreadsModelChanged();
    void runExecuteOnEachThread(GlobalVariablesContainer * glvcptr);

public slots:
    //add thread (from qml QFUNCTION?)
    void addThread(int threadsToAdd);
    void popBackThread();
    //expose number of threads in qml (from qml QFUNCTION?)
    int threadCount() const;

    void asignNodesGraphToThread(int nodesGraphId, int threadId);
    void updateQstringlistThreadsModel();
    void runAllThread();

private:
    QList<QPair<QThread*,ThreadWorker*>> threadsWithWorkers;
    GlobalVariablesContainer * m_gvcptr;
    NodesGraphContainer * m_nodesGraphContainer;
    QStringList m_qstringlistThreadsModel;
};

#endif // THREADMANAGER_H
