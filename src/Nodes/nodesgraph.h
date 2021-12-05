#ifndef NODESGRAPH_H
#define NODESGRAPH_H

#include <QMap>
#include "nodedata.h"
#include "iddistributor.h"
#include <QObject>



class NodesGraph : QObject
{
    Q_OBJECT
private:
    const unsigned int NODESLIMIT;
    IdDistributor * ID;

    QMap<unsigned int, NodeData *> m_nodes;
public:
    NodesGraph();
    ~NodesGraph();

    void execute();
    Q_INVOKABLE int createNode(const NodeType& type);
    Q_INVOKABLE void deleteNode(unsigned int id);
    Q_INVOKABLE void connectNodes(unsigned int idfrom, unsigned int idto, bool totrue = true);
    Q_INVOKABLE void disconnectNode(unsigned int id, bool totrue = true);
    Q_INVOKABLE NodeType GetType(unsigned int id) const;
};

#endif // NODESGRAPH_H
