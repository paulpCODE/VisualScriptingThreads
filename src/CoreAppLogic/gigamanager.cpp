#include "gigamanager.h"


GigaManager::GigaManager()
{
    globalVariablesContainer = new GlobalVariablesContainer();
    nodesGraphContainer = new NodesGraphContainer(globalVariablesContainer);
    threadManager = new ThreadManager(nodesGraphContainer);
}

GigaManager::~GigaManager(){
    delete nodesGraphContainer;
    delete globalVariablesContainer;
    delete threadManager;
}
