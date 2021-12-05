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
    int m_idTrue;
    int m_idFalse;
public:
    Connection(const ConnectionType& type);

    void makeConnection(const unsigned int id, const bool toTrue = true);
    void deleteConnection(const unsigned int id, const bool toTrue = true);
    int GetConnectedNodeId(const bool toTrue = true) const;
};

#endif // CONNECTION_H
