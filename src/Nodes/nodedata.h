#ifndef NODEDATA_H
#define NODEDATA_H

#include "connection.h"
#include <QPair>
#include <QString>



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
    const unsigned int m_id;
    NodeType m_type;
    Connection * m_connection;

    QPair<QString, QString> m_data;
public:
    NodeData(const unsigned int id, const NodeType& type);
    NodeData(const NodeData& other);
    ~NodeData();

    NodeType GetType() const;
    Connection* GetConnection() const;
    unsigned int GetId() const;
    void SetData(const QString& leftOperand, const QString& rightOperand);
};

#endif // NODEDATA_H
