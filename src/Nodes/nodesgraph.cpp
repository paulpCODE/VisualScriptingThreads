#include "nodesgraph.h"

NodesGraph::NodesGraph(const unsigned int id) : NODESLIMIT(100), m_id(id)
{
    ID = new IdDistributor(NODESLIMIT);
}

NodesGraph::~NodesGraph()
{
    delete ID;
}

void NodesGraph::execute(const GlobalVariablesContainer * const gvcptr)
{
    // #TODO
}

void NodesGraph::deepCopy(const NodesGraph& copyTarget)
{
    if(this->GetId() != copyTarget.GetId()) {
        qDebug("IDS OF GRAPHS NOT EQUAL IN deepCopy METHOD");
        return;
    }
    //to copy: IdDistributor, m_nodes
    *(this->ID) = *(copyTarget.ID); // maybe not GOOD, because * return rvalue?
    this->m_nodes.clear();
    for(auto &i : copyTarget.m_nodes) {
        NodeData * nd = new NodeData(*i);
        this->m_nodes.insert(nd->GetId(), nd);
    }
}

const unsigned int NodesGraph::createNode(const NodeType &type)
{
    unsigned int idForNode = ID->getFreeId();
    if(idForNode == 0) {
        qDebug("NODES LIMIT!");
        return idForNode;
    }
    m_nodes.insert(idForNode, new NodeData(idForNode, type));

    return idForNode;
}

void NodesGraph::deleteNode(unsigned int id)
{
    // #TODO Отсоединить ноду, которая присоединина к этой
    if(m_nodes.contains(id)) {
        ID->deleteID(id);
        m_nodes.remove(id);
    }
    qDebug("DONT EXIST NODE TO DELETE");
}

void NodesGraph::connectNodes(unsigned int idfrom, unsigned int idto, bool totrue)
{
    if(m_nodes.contains(idfrom) && m_nodes.contains(idto)) {
        m_nodes.take(idfrom)->GetConnection()->makeConnection(idto, totrue);
    }
    qDebug("DONT EXIST NODE TO CONNECT");
}

void NodesGraph::disconnectNode(unsigned int id, bool totrue)
{
    if(m_nodes.contains(id)) {
        m_nodes.take(id)->GetConnection()->deleteConnection(id, totrue);
    }
    qDebug("DONT EXIST NODE TO DISCONNECT");
}

NodeType NodesGraph::GetType(unsigned int id) const
{
    if(m_nodes.contains(id)) {
        return m_nodes[id]->GetType();
    }
    qDebug("DONT EXIST NODE TO GET TYPE. RETURN INCORRECT.");
    return NodeType::GlobalAssignConst;
}

const unsigned int NodesGraph::GetId() const
{
    return m_id;
}

void NodesGraph::SetNodeData(const unsigned int id, const QString &leftOperand, const QString &rightOperand)
{
    if(m_nodes.contains(id)) {
        m_nodes.take(id)->SetData(leftOperand, rightOperand);
        return;
    }
    qDebug("DONT EXIST NODE TO SET DATA");
}
