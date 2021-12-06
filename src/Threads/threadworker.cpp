#include "threadworker.h"

ThreadWorker::ThreadWorker(int graphInstanceId) :
    graphInstance(new NodesGraph(graphInstanceId))
{

}

void ThreadWorker::executeCurrentNodesGraph()
{
    //graphinstance->execute current node function
    //change curent node
}
