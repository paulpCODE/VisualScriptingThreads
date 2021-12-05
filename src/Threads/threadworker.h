#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QObject>

class ThreadWorker : public QObject
{
    Q_OBJECT
public:
    //NodesGraph graphinstance in constructor
    explicit ThreadWorker(QObject *parent = nullptr);

    //NodesGraph graphinstance
    //NodeData* currentGraphNode   id or pointer?
signals:

public slots:
    // main responsibility of class
    void executeCurrentNodeFunction();
};

#endif // THREADWORKER_H
