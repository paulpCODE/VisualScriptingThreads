#include "threadworker.h"

ThreadWorker::ThreadWorker() : graphInstance(nullptr)
{

}

void ThreadWorker::executeCurrentNodesGraph(GlobalVariablesContainer * glvcptr)
{
    graphInstance->execute(glvcptr);
}
