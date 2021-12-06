#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QObject>

#include"nodesgraph.h"

class ThreadWorker : public QObject
{
    Q_OBJECT
public:
    //NodesGraph seup after constructor? or by params don't know
    ThreadWorker(int graphInstanceId);

    NodesGraph *graphInstance;
    //NodeData* currentGraphNode   id or pointer?
signals:

public slots:
    // main responsibility of class
    // inside it move to next node
    void executeCurrentNodesGraph();
    //

};

#endif // THREADWORKER_H
