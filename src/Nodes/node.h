#include "AbstactNode.h"

#ifndef NODE_H
#define NODE_H


class Node : AbstractNode
{
private:
    NodeType m_type;
    AbstractNode * ptrToTrue;
public:
    Node(const NodeType& type);
    virtual ~Node() {}


    // AbstractNode interface
    void execute() override;
    void connect(AbstractNode * to, bool totrue) override;
    void disconnect(bool totrue) override;
    bool isConnectTo(AbstractNode *to, bool totrue) const override;
    NodeType type() const override;
};

#endif // NODE_H
