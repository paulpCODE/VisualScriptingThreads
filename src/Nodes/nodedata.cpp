#include "nodedata.h"

NodeData::NodeData(const unsigned int id, const NodeEnums::NodeType& type) : m_id(id), m_type(type)
{
    if(type == NodeEnums::NodeType::IfGlobalEqualGlobal || type == NodeEnums::NodeType::IfGlobalLessGlobal) {
        m_connection = new Connection(ConnectionType::DOUBLESIDED);
    }
    else {
        m_connection = new Connection(ConnectionType::ONESIDED);
    }
    qDebug() << "NODE " << id << " CREATED";
}

NodeData::NodeData(const NodeData &other) : m_id(other.m_id), m_type(other.m_type)
{
    m_data = other.m_data;
    m_connection = new Connection(*other.m_connection);
}

NodeData::~NodeData()
{
    delete m_connection;
}

NodeEnums::NodeType NodeData::GetType() const
{
    return m_type;
}

Connection *NodeData::GetConnection() const
{
    return m_connection;
}

unsigned int NodeData::GetId() const
{
    return m_id;
}

void NodeData::SetData(const QString &leftOperand, const QString &rightOperand)
{
    m_data = qMakePair(leftOperand, rightOperand);
}

const QPair<QString, QString> &NodeData::GetData() const
{
    return m_data;
}
