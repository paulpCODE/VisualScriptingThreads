#include "ifnode.h"



IfNode::IfNode(const NodeType &type)
{
    if(type != NodeType::IfGlobalEqualGlobal && type != NodeType::IfGlobalLessGlobal) {
        qDebug("Cant create ifNode with type for Node");
        return;
    }

    m_type = type;
    ptrToTrue = nullptr;
    ptrToFalse = nullptr;
}

void IfNode::execute()
{
// #TODO
}

void IfNode::connect(AbstractNode *to, bool totrue)
{
    if(totrue) {
        if(ptrToTrue == to) {
            qDebug("Already connected");
            return;
        }
        ptrToTrue = to;
        return;
    }

    if(ptrToFalse == to) {
        qDebug("Already connected");
        return;
    }

    ptrToFalse = to;
}

void IfNode::disconnect(bool totrue)
{
    if(totrue) {
        if(!ptrToTrue) {
            qDebug("Already null");
            return;
        }

        ptrToTrue = nullptr;
        return;
    }

    if(!ptrToFalse) {
        qDebug("Already null");
    }

    ptrToFalse = nullptr;
}

bool IfNode::isConnectTo(AbstractNode *to, bool totrue) const
{
    if(totrue && ptrToTrue == to) {
        return true;
    }
    if(!totrue && ptrToFalse == to) {
        return true;
    }
    return false;
}

NodeType IfNode::type() const
{
    return m_type;
}
