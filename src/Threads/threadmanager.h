#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QVector>
#include <QThread>
#include "threadworker.h"
class ThreadManager: public QObject
{
    //#TODO

    //add to threadId NodesGraph instance by it's id
    // id distributor

public:
    ThreadManager();


public slots:
    //add thread (from qml QFUNCTION?)
    void addThread(int threadsToAdd);
    void popBackThread();
    //expose number of threads in qml (from qml QFUNCTION?)
    int threadCount() const;

private:
    QVector<QThread*> m_threads;
    QVector<ThreadWorker*> m_threadWorkers;

};

#endif // THREADMANAGER_H
