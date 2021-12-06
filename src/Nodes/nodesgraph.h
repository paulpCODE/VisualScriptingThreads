#ifndef NODESGRAPH_H
#define NODESGRAPH_H
#include <QMap>
#include "nodedata.h"
#include "iddistributor.h"
#include "globalvariablescontainer.h"
#include <QObject>




class NodesGraph : public QObject
{
    Q_OBJECT
private:
    const unsigned int NODESLIMIT;
    const unsigned int m_id;

    unsigned int m_startNodeId;

    IdDistributor * ID;

    QMap<unsigned int, NodeData*> m_nodes;
public:
    NodesGraph(const unsigned int id);
    ~NodesGraph();

    void execute(GlobalVariablesContainer * const gvcptr);
    /*
    target - new NodesGraph instace(copy of other)
    other - Copied object

    Use construction
    NodesGraph instance(copyTarget.GetId()
    instance.deepCopy(copyTarget)
    to copy and give new instance of class NodesGraph.
    If ids of two objects not equal -> return empty targer without data
    */
    void deepCopy(const NodesGraph& copyTarget);
    Q_INVOKABLE const unsigned int createNode(const NodeType& type);
    Q_INVOKABLE void deleteNode(unsigned int id);
    Q_INVOKABLE void connectNodes(unsigned int idfrom, unsigned int idto, bool totrue = true);
    Q_INVOKABLE void disconnectNode(unsigned int id, bool totrue = true);
    Q_INVOKABLE NodeType GetType(unsigned int id) const;
    Q_INVOKABLE const unsigned int GetId() const;
    Q_INVOKABLE void SetNodeData(const unsigned int id, const QString& leftOperand, const QString& rightOperand);
    Q_INVOKABLE void SetStartNodeId(const unsigned int id);
};

#endif // NODESGRAPH_H
