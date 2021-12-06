#ifndef IDDISTRIBUTOR_H
#define IDDISTRIBUTOR_H

#include <QVector>




class IdDistributor
{
private:
    const unsigned int ID_LIMIT;
    // true - free. false - busy
    QVector<bool> m_ids;
public:
    IdDistributor(const unsigned int idLimit);
    IdDistributor& operator=(const IdDistributor& right);

    unsigned int getFreeId();
    void deleteID(unsigned int idToDelete);

private:
    bool addNew();
};

#endif // IDDISTRIBUTOR_H
