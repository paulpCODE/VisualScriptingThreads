#include "nodesgraphcontainer.h"

NodesGraphContainer::NodesGraphContainer(GlobalVariablesContainer * const gvcptr) : GRAPHSLIMIT(100)
{
    m_gvcptr = gvcptr;
    ID = new IdDistributor(GRAPHSLIMIT);

    connect(this,&NodesGraphContainer::usingNewGlobalVariable,m_gvcptr,&GlobalVariablesContainer::increaseUsageCounter);
    connect(this,&NodesGraphContainer::noLongerUsingGlobalVariable,m_gvcptr,&GlobalVariablesContainer::decreaseUsageCounter);
}

NodesGraphContainer::~NodesGraphContainer()
{
    m_gvcptr = nullptr;
    delete ID;
}

const QList<NodesGraph *> *NodesGraphContainer::GraphsList() const
{
    return &m_graphsList;
}

void NodesGraphContainer::executeGraph(const unsigned int id)
{
    for(auto &i : m_graphsList) {
        if(i->GetId() == id) {
            i->execute(m_gvcptr);
            return;
        }
    }
    qDebug("DONT EXIST GRAPH TO EXECUTE");
}

const unsigned int NodesGraphContainer::addGraph()
{
    unsigned int idForGraph = ID->getFreeId();
    if(idForGraph == 0) {
        qDebug("GRAPHS LIMIT!");
        return idForGraph;
    }
    m_graphsList.push_back(new NodesGraph(idForGraph));
    return idForGraph;
}

void NodesGraphContainer::deleteGraph(const unsigned int id)
{
    QMutableListIterator<NodesGraph*> i(m_graphsList);
    while (i.hasNext()) {
        if (i.next()->GetId() == id)
            i.next()->deleteLater();
        i.remove();
        return;
    }
    qDebug("DONT EXIST GRAPH TO DELETE");
}

NodesGraph* NodesGraphContainer::GetGraph(const unsigned int id) const
{
    for(auto &i : m_graphsList) {
        if(i->GetId() == id) {
            return i;
        }
    }
    qDebug("DONT EXIST GRAPH. RETURN INCORRECT.");
    return m_graphsList.first();
}

const unsigned int NodesGraphContainer::createNode(const unsigned int graphid, const NodeEnums::NodeType &type)
{
    return GetGraph(graphid)->createNode(type);
}

void NodesGraphContainer::deleteNode(const unsigned int graphid, unsigned int id)
{
    auto currentNodeType =  GetGraph(graphid)->GetType(id);
    if (currentNodeType == NodeEnums::NodeType::InputGlobal ||
            currentNodeType == NodeEnums::NodeType::GlobalAssignConst||
            currentNodeType == NodeEnums::NodeType::GlobalAssignGlobal)
    {
        auto oldLeft = GetNodeOperandsData(graphid,id).first;
        auto oldRight = GetNodeOperandsData(graphid,id).second;
        emit noLongerUsingGlobalVariable(oldLeft);
        if( currentNodeType == NodeEnums::NodeType::GlobalAssignGlobal){
            emit noLongerUsingGlobalVariable(oldRight);
        }
    }
    GetGraph(graphid)->deleteNode(id);
}

void NodesGraphContainer::connectNodes(const unsigned int graphid, unsigned int idfrom, unsigned int idto, bool totrue)
{
    GetGraph(graphid)->connectNodes(idfrom, idto, totrue);
}

void NodesGraphContainer::disconnectNode(const unsigned int graphid, unsigned int id, bool totrue)
{
    GetGraph(graphid)->disconnectNode(id, totrue);
}

void NodesGraphContainer::SetNodeData(const unsigned int graphid, const unsigned int id, const QString &leftOperand, const QString &rightOperand)
{
    NodeEnums::NodeType currentNodeType =  GetGraph(graphid)->GetType(id);
    // left operand is global var
    if (currentNodeType == NodeEnums::NodeType::InputGlobal ||
            currentNodeType == NodeEnums::NodeType::GlobalAssignConst||
            currentNodeType == NodeEnums::NodeType::GlobalAssignGlobal)
    {
        auto oldLeft = GetNodeOperandsData(graphid,id).first;
        auto oldRight = GetNodeOperandsData(graphid,id).second;
        // if exist such left variable
        if(m_gvcptr->globalVariableByName(leftOperand)!=nullptr)
        {
            // notify that old var no longer using
            if (oldLeft != "" && oldLeft != leftOperand)
            {
               emit noLongerUsingGlobalVariable(oldLeft);
            }
            // notify that now we are using leftOperand
            emit usingNewGlobalVariable(leftOperand);

             // if exist such right variable and GlobalAssignGlobal
           if(currentNodeType == NodeEnums::NodeType::GlobalAssignGlobal &&
                   (m_gvcptr->globalVariableByName(rightOperand)!=nullptr))
           {
               // notify that old var no longer using
               if (oldRight != "" && oldRight != rightOperand)
               {
                  emit noLongerUsingGlobalVariable(oldRight);
               }
               // notify that now we are using rightOperand
               emit usingNewGlobalVariable(rightOperand);
           }
           else if(currentNodeType == NodeEnums::NodeType::GlobalAssignGlobal &&
                      (m_gvcptr->globalVariableByName(rightOperand)==nullptr)){
                qDebug("RIGHT OPERAND VARIABLE DON'T EXIST. RETURN INCORRECT.");
           }
        }
        else{
            qDebug("LEFT OPERAND VARIABLE DON'T EXIST. RETURN INCORRECT.");
            return;
        }
    }
    GetGraph(graphid)->SetNodeData(id, leftOperand, rightOperand);
}

QPair<QString,QString> NodesGraphContainer::GetNodeOperandsData(const unsigned int graphid, const unsigned int id)
{
     return GetGraph(graphid)->GetNodeOperandsData(id);
}

void NodesGraphContainer::SetStartNodeId(const unsigned int graphid, const unsigned int id)
{
    GetGraph(graphid)->SetStartNodeId(id);
}
