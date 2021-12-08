#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QObject>

#include"nodesgraph.h"

class ThreadWorker : public QObject
{
    Q_OBJECT
public:
    ThreadWorker();

    NodesGraph *graphInstance;


    //NodeData* currentGraphNode   id or pointer?
public slots:
    // main responsibility of class
    // inside it move to next node
    void executeCurrentNodesGraph(GlobalVariablesContainer * glvcptr);



};

#endif // THREADWORKER_H
