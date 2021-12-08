#include "nodesgraph.h"


NodesGraph::NodesGraph(const unsigned int id,const QString &graphName) : NODESLIMIT(100), m_id(id), m_startNodeId(0)
{
    ID = new IdDistributor(NODESLIMIT);
    m_graphName = graphName;
}

NodesGraph::~NodesGraph()
{
    delete ID;
}

void NodesGraph::execute(GlobalVariablesContainer * const gvcptr)
{
    unsigned int executableId = 0;
    bool totrue = true;

    if(m_startNodeId == 0) {
        qDebug("NOTHING TO EXECUTE");
        return;
    }
    if(!m_nodes.contains(m_startNodeId)) {
        qDebug("DONT EXIST START NODE TO EXECUTE");
        return;
    }

    executableId = m_startNodeId;

    while (true) {
        const NodeData executableNode(*m_nodes[executableId]);
        const QString leftOperand = executableNode.GetData().first;
        const QString rightOperand = executableNode.GetData().second;
        switch (executableNode.GetType()) {
        case NodeEnums::NodeType::GlobalAssignGlobal:
            //mutex lock
            gvcptr->globalVariableByName(leftOperand)->setValue(gvcptr->globalVariableByName(rightOperand)->value());
            break;
        case NodeEnums::NodeType::GlobalAssignConst:
            //mutex lock
            gvcptr->globalVariableByName(leftOperand)->setValue(rightOperand.toInt());
            break;
        case NodeEnums::NodeType::InputGlobal:
            // #TODO
            break;
        case NodeEnums::NodeType::PrintGlobal:
            //mutex lock
            qDebug() << gvcptr->globalVariableByName(leftOperand) << ": " << gvcptr->globalVariableByName(leftOperand)->value();
            break;
        case NodeEnums::NodeType::IfGlobalEqualGlobal:
            //mutex lock
            if(gvcptr->globalVariableByName(leftOperand)->value() == rightOperand.toInt()) {
                totrue = true;
            } else {
                totrue = false;
            }
            break;
        case NodeEnums::NodeType::IfGlobalLessGlobal:
            //mutex lock
            if(gvcptr->globalVariableByName(leftOperand)->value() < rightOperand.toInt()) {
                totrue = true;
            } else  {
                totrue = false;
            }
            break;
        }
        if(executableNode.GetConnection()->GetConnectedNodeId(totrue) == 0) {
            qDebug("EXECUTED");
            return;
        }

        executableId = executableNode.GetConnection()->GetConnectedNodeId(totrue);
    }
}

void NodesGraph::deepCopy(const NodesGraph& copyTarget)
{
    //if(this->GetId() != copyTarget.GetId()) {
    //    qDebug("IDS OF GRAPHS NOT EQUAL IN deepCopy METHOD");
    //    return;
    //}
    //to copy: IdDistributor, m_nodes
    this->ID = nullptr;
    this->ID = new IdDistributor(*copyTarget.ID);
//    *(this->ID) = *(copyTarget.ID); // maybe not GOOD, because * return rvalue?
    this->m_nodes.clear();
    for(auto &i : copyTarget.m_nodes) {
        NodeData * nd = new NodeData(*i);
        this->m_nodes.insert(nd->GetId(), nd);
    }
}

const unsigned int NodesGraph::createNode(const NodeEnums::NodeType &type)
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
        for(auto &i : m_nodes) {
            if(i->GetConnection()->GetConnectedNodeId() == id) {
                i->GetConnection()->deleteConnection(i->GetId());
            }
            if(i->GetConnection()->GetConnectedNodeId(false) == id) {
                i->GetConnection()->deleteConnection(i->GetId(), false);
            }
        }
        ID->releaseID(id);



        m_nodes.remove(id);
        return;
    }
    qDebug("DONT EXIST NODE TO DELETE");




}

void NodesGraph::connectNodes(unsigned int idfrom, unsigned int idto, bool totrue)
{
    if(m_nodes.contains(idfrom) && m_nodes.contains(idto)) {
        m_nodes[idfrom]->GetConnection()->makeConnection(idto, totrue);
        return;
    }
    qDebug("DONT EXIST NODE TO CONNECT");
}

void NodesGraph::disconnectNode(unsigned int id, bool totrue)
{
    if(m_nodes.contains(id)) {
        m_nodes[id]->GetConnection()->deleteConnection(id, totrue);
        return;
    }
    qDebug("DONT EXIST NODE TO DISCONNECT");
}

NodeEnums::NodeType NodesGraph::GetType(unsigned int id) const
{
    if(m_nodes.contains(id)) {
        return m_nodes[id]->GetType();
    }
    qDebug("DONT EXIST NODE TO GET TYPE. RETURN INCORRECT.");
    return NodeEnums::NodeType::GlobalAssignConst;
}

const unsigned int NodesGraph::GetId() const
{
    return m_id;
}

void NodesGraph::SetNodeData(const unsigned int id, const QString &leftOperand, const QString &rightOperand)
{
    if(m_nodes.contains(id)) {
        m_nodes[id]->SetData(leftOperand, rightOperand);
        return;
    }
    qDebug("DONT EXIST NODE TO SET DATA");
}

QPair<QString, QString> NodesGraph::GetNodeOperandsData(const unsigned int id) const
{
    if(m_nodes.contains(id)) {
        return m_nodes[id]->GetData();
    }
    qDebug("DONT EXIST NODE TO GET DATA");
    return qMakePair("empty","empty");
}

QString NodesGraph::convertToQString()
{
     return QString( m_graphName  +  QString::number(m_id));
}

void NodesGraph::SetStartNodeId(const unsigned int id)
{
    m_startNodeId = id;
}

const QString &NodesGraph::graphName() const
{
    return m_graphName;
}

void NodesGraph::setGraphName(const QString &newGraphName)
{
    if (m_graphName == newGraphName)
        return;
    m_graphName = newGraphName;
    emit graphNameChanged();
}
const unsigned int NodesGraph::GetConnectedNodeId(const unsigned int id, bool totrue)
{
    if(m_nodes.contains(id)) {
        return m_nodes[id]->GetConnection()->GetConnectedNodeId(totrue);
    }
    qDebug("DONT EXIST NODE TO RETURN ID");
    return 0;
}
