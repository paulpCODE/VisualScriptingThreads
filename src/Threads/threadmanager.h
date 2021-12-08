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
    //#TODO

    //add to threadId NodesGraph instance by it's id
    // id distributor

public:
    ThreadManager( NodesGraphContainer * nodesGraphContainer );

    const QStringList &qstringlistThreadsModel() const;
    void setQstringlistThreadsModel(const QStringList &newQstringlistThreadsModel);
signals:
    void qstringlistThreadsModelChanged();
public slots:
    //add thread (from qml QFUNCTION?)
    void addThread(int threadsToAdd);
    void popBackThread();
    //expose number of threads in qml (from qml QFUNCTION?)
    int threadCount() const;
    void asignNodesGraphToThread(int nodesGraphId, int threadId);


private:
    QVector<QThread*> m_threads;
    QVector<ThreadWorker*> m_threadWorkers;

    NodesGraphContainer * m_nodesGraphContainer;
    QStringList m_qstringlistThreadsModel;
};

#endif // THREADMANAGER_H
