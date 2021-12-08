#include "threadmanager.h"
#include <QDebug>

ThreadManager::ThreadManager(NodesGraphContainer *  nodesGraphContainer)
    :m_nodesGraphContainer(nodesGraphContainer)
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
    ThreadWorker *newThreadWorker = new ThreadWorker(nodesGraphId);
    //NodesGraphContainer::asign( |Lvalue| newThreadWorker->graphInstance ,
    //                              |Rvalue|NodesGraphContainer.GetGraph(nodesGraphId) )
    // need deep copy
    newThreadWorker->graphInstance->deepCopy(
                 *m_nodesGraphContainer->GetGraph(nodesGraphId));

    //TEST
        if(newThreadWorker->graphInstance == m_nodesGraphContainer->GetGraph(nodesGraphId) ){
            qDebug()<<"fake copy constructor not working properly \n" ;
        }
    //TEST

    m_threadWorkers.push_back(newThreadWorker);

}




const QStringList &ThreadManager::qstringlistThreadsModel() const
{
    return m_qstringlistThreadsModel;
}

void ThreadManager::setQstringlistThreadsModel(const QStringList &newQstringlistThreadsModel)
{
    if (m_qstringlistThreadsModel == newQstringlistThreadsModel)
        return;
    m_qstringlistThreadsModel = newQstringlistThreadsModel;
    emit qstringlistThreadsModelChanged();
}
