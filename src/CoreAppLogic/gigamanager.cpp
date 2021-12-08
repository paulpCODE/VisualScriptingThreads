#include "gigamanager.h"


GigaManager::GigaManager()
{
    globalVariablesContainer = new GlobalVariablesContainer();
    nodesGraphContainer = new NodesGraphContainer(globalVariablesContainer);
    threadManager = new ThreadManager(nodesGraphContainer,globalVariablesContainer);
}

GigaManager::~GigaManager(){
    delete nodesGraphContainer;
    delete globalVariablesContainer;
    delete threadManager;
}
