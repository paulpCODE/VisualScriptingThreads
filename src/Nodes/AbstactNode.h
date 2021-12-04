#include <QObject>

#ifndef ABSTACTNODE_H
#define ABSTACTNODE_H

enum class NodeType {
    GlobalAssignGlobal,
    GlobalAssignConst,
    InputGlobal,
    PrintGlobal,
    GlobalEqualGlobal,
    GlobalLessGlobal
};

class AbstractNode : public QObject {
protected:
    NodeType type;
    AbstractNode * totrue;

public:
    virtual void execute() = 0;
    virtual bool connect(const AbstractNode * const to, bool totrue = true) = 0;
    virtual bool disconnect(bool totrue = true) = 0;
    virtual bool isConnectTo(AbstractNode * to) const = 0;
};

#endif // ABSTACTNODE_H
