#include <QMap>
#include <AbstactNode.h>

#ifndef NODESGRAPH_H
#define NODESGRAPH_H


class NodesGraph : QObject
{
    Q_OBJECT
private:
    QMap<unsigned char, AbstractNode*> m_nodes;
public:
    NodesGraph();

    void execute();
    Q_INVOKABLE void createNode(const NodeType& type);
    Q_INVOKABLE void changeType(unsigned char id, NodeType& type);
    Q_INVOKABLE void deleteNode(unsigned char id);
    Q_INVOKABLE void connectNodes(unsigned char idfrom, unsigned char idto, bool totrue = true);
    Q_INVOKABLE void disconnectNode(unsigned char id, bool totrue = true);
    Q_INVOKABLE NodeType GetType(unsigned char id) const;
};

#endif // NODESGRAPH_H
