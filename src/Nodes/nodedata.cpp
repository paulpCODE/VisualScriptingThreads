#include "nodedata.h"

NodeData::NodeData(const unsigned int id, const NodeType& type) : m_id(id), m_type(type)
{
    if(type == NodeType::IfGlobalEqualGlobal || type == NodeType::IfGlobalLessGlobal) {
        m_connection = new Connection(ConnectionType::DOUBLESIDED);
    }
    else {
        m_connection = new Connection(ConnectionType::ONESIDED);
    }
}

NodeData::~NodeData()
{
    delete m_connection;
}

NodeType NodeData::GetType() const
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
