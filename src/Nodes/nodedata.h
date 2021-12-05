#include "connection.h"

#ifndef NODEDATA_H
#define NODEDATA_H

enum class NodeType {
    GlobalAssignGlobal,
    GlobalAssignConst,
    InputGlobal,
    PrintGlobal,
    IfGlobalEqualGlobal,
    IfGlobalLessGlobal
};

class NodeData
{
private:
    unsigned int m_id;
    NodeType m_type;
    Connection * m_connection;
public:
    NodeData(const unsigned int id, const NodeType& type);
    ~NodeData();

    NodeType GetType() const;
    Connection* GetConnection() const;
    unsigned int GetId() const;
};

#endif // NODEDATA_H
