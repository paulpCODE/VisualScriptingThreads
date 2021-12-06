#include "connection.h"

Connection::Connection(const ConnectionType& type) : m_type(type), m_idTrue(0), m_idFalse(0)
{}

Connection::Connection(const Connection &other) : m_type(other.m_type), m_idTrue(other.m_idTrue), m_idFalse(other.m_idFalse)
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
        m_idTrue = 0;
        return;
    }

    if(toTrue) {
        m_idTrue = 0;
        return;
    }
    m_idFalse = 0;
}

unsigned int Connection::GetConnectedNodeId(const bool toTrue) const
{
    if(m_type == ConnectionType::ONESIDED) {
        return m_idTrue;
    }

    if(toTrue) {
        return m_idTrue;
    }

    return m_idFalse;
}
