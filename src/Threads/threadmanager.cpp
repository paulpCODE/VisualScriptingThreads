#include "threadmanager.h"
#include <QDebug>

ThreadManager::ThreadManager(NodesGraphContainer *  nodesGraphContainer, GlobalVariablesContainer* gvcptr)
    :m_nodesGraphContainer(nodesGraphContainer),m_gvcptr(gvcptr)
{

}

void ThreadManager::addThread(int threadsToAdd)
{
    if(threadsWithWorkers.size()>100){
        qDebug()<<"Can't add new thread, max limit exceeded \n";
        return;
    }
    for(int i =0 ;i<threadsToAdd;i++){
        threadsWithWorkers.push_back(qMakePair(new QThread,new ThreadWorker));
    }
}

void ThreadManager::popBackThread()
{
    if(threadsWithWorkers.size()!=0){
        threadsWithWorkers.pop_back();
        updateQstringlistThreadsModel();
    }
}

int ThreadManager::threadCount() const
{
    return threadsWithWorkers.size();
}

void ThreadManager::asignNodesGraphToThread(int nodesGraphId, int threadId)
{
    threadsWithWorkers[threadId].second->graphInstance->deepCopy(*m_nodesGraphContainer->GetGraph(nodesGraphId));
    //NodesGraphContainer::asign( |Lvalue| newThreadWorker->graphInstance ,
    //                              |Rvalue|NodesGraphContainer.GetGraph(nodesGraphId) )
    // need deep copy

    //TEST
    if(threadsWithWorkers[threadId].second->graphInstance == m_nodesGraphContainer->GetGraph(nodesGraphId) ){
        qDebug()<<"fake copy constructor not working properly \n";
    }
    //TEST
    updateQstringlistThreadsModel();

    //assigning worker to thread
    threadsWithWorkers[threadId].second->moveToThread(threadsWithWorkers[threadId].first);

    connect(this,&ThreadManager::runExecuteOnEachThread,
            threadsWithWorkers[threadId].second,&ThreadWorker::executeCurrentNodesGraph,Qt::QueuedConnection);

}

void ThreadManager::updateQstringlistThreadsModel()
{
    QStringList newList;
    for(int i =0;i<threadsWithWorkers.size();i++){
        if(!threadsWithWorkers[i].second->graphInstance){
            newList.push_back("_thread_"+QString::number(i)+ " is free") ;
        }
        else{
            newList.push_back("_thread_"+QString::number(i)+ " owns " +
                              threadsWithWorkers[i].second->graphInstance->graphName());
        }
    }
    m_qstringlistThreadsModel = newList;
    emit qstringlistThreadsModelChanged();
}

void ThreadManager::runAllThread()
{
    for(const auto &i:threadsWithWorkers){
        i.first->start();
    }
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
