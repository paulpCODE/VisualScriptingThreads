#include "node.h"


Node::Node(const NodeType &type)
{
    if(type == NodeType::IfGlobalEqualGlobal || type == NodeType::IfGlobalLessGlobal) {
        qDebug("Cant create Node with type for IfNode");
        return;
    }
    m_type = type;
    ptrToTrue = nullptr;
}

void Node::execute()
{
// #TODO
}

void Node::connect(AbstractNode * to, bool totrue)
{
    if(ptrToTrue == to) {
        qDebug("Already connected");
        return;
    }

    ptrToTrue = to;
}

void Node::disconnect(bool totrue)
{
    if(!ptrToTrue) {
        qDebug("Already null");
        return;
    }

    ptrToTrue = nullptr;
}

bool Node::isConnectTo(AbstractNode *to, bool totrue) const
{
    if(ptrToTrue == to) {
        return true;
    }
    return false;
}

NodeType Node::type() const
{
    return m_type;
}
