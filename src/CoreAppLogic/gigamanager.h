#ifndef GIGAMANAGER_H
#define GIGAMANAGER_H
#include "globalvariablescontainer.h"
#include "threadmanager.h"
#include "nodesgraphcontainer.h"

class GigaManager
{
public:
    GigaManager();
    ~GigaManager();
    NodesGraphContainer *nodesGraphContainer;
    GlobalVariablesContainer *globalVariablesContainer;
    ThreadManager *threadManager;


};

#endif // GIGAMANAGER_H
