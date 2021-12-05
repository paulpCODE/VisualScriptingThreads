#ifndef IFNODE_H
#define IFNODE_H
#include "AbstactNode.h"

#include <QObject>

class IfNode : public AbstractNode
{
private:
    NodeType m_type;
    AbstractNode * ptrToTrue;
    AbstractNode * ptrToFalse;
public:
    IfNode(const NodeType& type);
    virtual ~IfNode() {};

    // AbstractNode interface
    void execute() override;
    void connect(AbstractNode *to, bool totrue) override;
    void disconnect(bool totrue) override;
    bool isConnectTo(AbstractNode *to, bool totrue) const override;
    NodeType type() const override;
};

#endif // IFNODE_H
