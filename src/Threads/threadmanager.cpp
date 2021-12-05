#include "threadmanager.h"
#include <QDebug>

ThreadManager::ThreadManager()
{

}

void ThreadManager::addThread(int threadsToAdd)
{
    if(m_threads.size()>100){
        qDebug()<<"Can't add new thread, max limit exceeded \n";
        return;
    }
    for(int i =0 ;i<threadsToAdd;i++){
        m_threads.push_back(new QThread());
    }
}

void ThreadManager::popBackThread()
{
    if(m_threads.size()!=0){
        m_threads.pop_back();
    }
}

int ThreadManager::threadCount() const
{
    return m_threads.size();
}

void ThreadManager::asignNodesGraphToThread(int nodesGraphId, int threadId)
{
    ThreadWorker *newThreadWorker = new ThreadWorker();
    //NodesGraphContainer::asign( |Lvalue| newThreadWorker->graphInstance ,
    //                              |Rvalue|NodesGraphContainer.GetGraph(nodesGraphId) )
    // need deep copy
    m_threadWorkers.push_back(newThreadWorker);

}



