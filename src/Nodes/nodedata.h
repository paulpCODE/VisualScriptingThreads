#ifndef NODEDATA_H
#define NODEDATA_H

#include "connection.h"
#include <QPair>
#include <QString>
#include <QObject>
#include <QDebug>

class NodeEnums : public QObject {
    Q_GADGET
public:
    enum class NodeType {
        GlobalAssignGlobal,
        GlobalAssignConst,
        InputGlobal,
        PrintGlobal,
        IfGlobalEqualGlobal,
        IfGlobalLessGlobal
    };
    Q_ENUMS(NodeType)
};

//enum class NodeType {
//    GlobalAssignGlobal,
//    GlobalAssignConst,
//    InputGlobal,
//    PrintGlobal,
//    IfGlobalEqualGlobal,
//    IfGlobalLessGlobal
//};
//Q_ENUMS(NodeType)

class NodeData
{
private:
    const unsigned int m_id;
    NodeEnums::NodeType m_type;
    Connection * m_connection;

    QPair<QString, QString> m_data;
public:
    NodeData(const unsigned int id, const NodeEnums::NodeType& type);
    NodeData(const NodeData& other);
    ~NodeData();

    NodeEnums::NodeType GetType() const;
    Connection* GetConnection() const;
    unsigned int GetId() const;
    void SetData(const QString& leftOperand, const QString& rightOperand);
    const QPair<QString,QString>& GetData() const;
};

#endif // NODEDATA_H
