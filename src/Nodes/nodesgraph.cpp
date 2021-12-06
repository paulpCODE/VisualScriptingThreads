#include "nodesgraph.h"

NodesGraph::NodesGraph(const unsigned int id) : NODESLIMIT(100), m_id(id), m_startNodeId(0)
{
    ID = new IdDistributor(NODESLIMIT);
}

NodesGraph::~NodesGraph()
{
    delete ID;
}

void NodesGraph::execute(GlobalVariablesContainer * const gvcptr)
{
    static bool startNodeFixed = false;
    static unsigned int executableId = 0;
    if(m_startNodeId == 0) {
        qDebug("NOTHING TO EXECUTE");
        return;
    }
    if(!startNodeFixed) {
        if(!m_nodes.contains(m_startNodeId)) {
            qDebug("DONT EXIST START NODE TO EXECUTE");
            return;
        }
        executableId = m_startNodeId;
        startNodeFixed = true;
    }

    bool totrue = true;
    const NodeData executableNode(*m_nodes.take(executableId));
    const QString leftOperand = executableNode.GetData().first;
    const QString rightOperand = executableNode.GetData().second;
    switch (executableNode.GetType()) {
    case NodeType::GlobalAssignGlobal:
        //mutex lock
        gvcptr->globalVariableByName(leftOperand)->setValue(gvcptr->globalVariableByName(rightOperand)->value());
        break;
    case NodeType::GlobalAssignConst:
        //mutex lock
        gvcptr->globalVariableByName(leftOperand)->setValue(rightOperand.toInt());
        break;
    case NodeType::InputGlobal:
        // #TODO
        break;
    case NodeType::PrintGlobal:
        //mutex lock
        qDebug() << gvcptr->globalVariableByName(leftOperand) << ": " << gvcptr->globalVariableByName(leftOperand)->value();
        break;
    case NodeType::IfGlobalEqualGlobal:
        //mutex lock
        if(gvcptr->globalVariableByName(leftOperand)->value() != rightOperand.toInt()) {
            totrue = false;
        }
        break;
    case NodeType::IfGlobalLessGlobal:
        //mutex lock
        if(gvcptr->globalVariableByName(leftOperand)->value() >= rightOperand.toInt()) {
            totrue = false;
        }
        break;
    }

    if(executableNode.GetConnection()->GetConnectedNodeId(totrue) == 0) {
        startNodeFixed = false;
        executableId = 0;
        return;
    }

    executableId = executableNode.GetConnection()->GetConnectedNodeId(totrue);

    execute(gvcptr);
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

void NodesGraph::SetStartNodeId(const unsigned int id)
{
    m_startNodeId = id;
}
