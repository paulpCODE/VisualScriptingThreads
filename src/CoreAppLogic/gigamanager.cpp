#include "gigamanager.h"


GigaManager::GigaManager()
{
    //nodesGraphContainer = new NodesGraphContainer();
    globalVariablesContainer = new GlobalVariablesContainer();
    //threadManager = new ThreadManager();
}

GigaManager::~GigaManager(){
    delete nodesGraphContainer;
    delete globalVariablesContainer;
    delete threadManager;
}
