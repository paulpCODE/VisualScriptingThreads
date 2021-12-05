#include "connection.h"

Connection::Connection(const ConnectionType& type) : m_type(type), m_idTrue(-1), m_idFalse(-1)
{}

void Connection::makeConnection(const unsigned int id, const bool toTrue)
{
    if(m_type == ConnectionType::ONESIDED) {
        m_idTrue = id;
        return;
    }
    if(toTrue) {
        m_idTrue = id;
        return;
    }
    m_idFalse = id;
}

void Connection::deleteConnection(const unsigned int id, const bool toTrue)
{
    if(m_type == ConnectionType::ONESIDED) {
        m_idTrue = -1;
        return;
    }

    if(toTrue) {
        m_idTrue = -1;
        return;
    }
    m_idFalse = -1;
}

int Connection::GetConnectedNodeId(const bool toTrue) const
{
    if(m_type == ConnectionType::ONESIDED) {
        return m_idTrue;
    }

    if(toTrue) {
        return m_idTrue;
    }

    return m_idFalse;
}