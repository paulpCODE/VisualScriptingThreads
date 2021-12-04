#include "AbstactNode.h"

#ifndef NODE_H
#define NODE_H


class Node : AbstractNode
{
public:
    Node(const NodeType& type, AbstractNode * connect = nullptr);


    void execute() override;
    bool connect(const AbstractNode * const to, bool totrue) override;
    bool disconnect(bool totrue) override;
    bool isConnectTo(AbstractNode *to) const override;
};

#endif // NODE_H
