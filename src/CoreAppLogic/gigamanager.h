#ifndef GIGAMANAGER_H
#define GIGAMANAGER_H
#include "globalvariablescontainer.h"

class NodesGraphContainer;
class ThreadManager;

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
