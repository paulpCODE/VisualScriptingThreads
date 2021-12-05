#include <QObject>

#ifndef ABSTACTNODE_H
#define ABSTACTNODE_H

enum class NodeType {
    GlobalAssignGlobal,
    GlobalAssignConst,
    InputGlobal,
    PrintGlobal,
    IfGlobalEqualGlobal,
    IfGlobalLessGlobal
};

class AbstractNode {
public:
    virtual void execute() = 0;
    virtual void connect(AbstractNode * to, bool totrue = true) = 0;
    virtual void disconnect(bool totrue = true) = 0;
    virtual bool isConnectTo(AbstractNode * to, bool totrue = true) const = 0;
    virtual NodeType type() const = 0;
};

#endif // ABSTACTNODE_H
