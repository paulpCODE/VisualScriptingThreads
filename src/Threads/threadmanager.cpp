#include "threadmanager.h"

ThreadManager::ThreadManager()
{

}

void ThreadManager::addThread(int threadsToAdd)
{
    for(int i =0 ;i<threadsToAdd;i++){
        m_threads.push_back(new QThread());
    }
}

int ThreadManager::threadCount() const
{
    return m_threads.size();
}



