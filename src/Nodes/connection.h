#ifndef CONNECTION_H
#define CONNECTION_H

enum class ConnectionType {
    ONESIDED,
    DOUBLESIDED
};

class Connection
{
private:
    ConnectionType m_type;
    unsigned int m_idTrue;
    unsigned int m_idFalse;
public:
    Connection(const ConnectionType& type);
    Connection(const Connection& other);

    void makeConnection(const unsigned int id, const bool toTrue = true);
    void deleteConnection(const unsigned int id, const bool toTrue = true);
    unsigned int GetConnectedNodeId(const bool toTrue = true) const;
};

#endif // CONNECTION_H
