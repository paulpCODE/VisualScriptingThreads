#ifndef IDDISTRIBUTOR_H
#define IDDISTRIBUTOR_H

//#include <QVector>
#include <vector>

using std::vector;

class IdDistributor
{
private:
    // Maximum of ids which may created.
    const unsigned int ID_LIMIT;
    // true - free. false - busy
    vector<bool> m_ids;
public:
    IdDistributor(const unsigned int idLimit);
    IdDistributor(const IdDistributor& right);
    IdDistributor& operator=(const IdDistributor& right);
    /*
    Returns free id. WARNING: You can call this function only one time for each id.
    If object with this id deleted than id must be released. Call function releaseId(unsigned int id)
    */
    unsigned int getFreeId();
    /*
    Releases id.
    */
    void releaseID(unsigned int idToRelease);

private:
    // DONT USE THIS FUNCTION.
    bool addNew();
};

#endif // IDDISTRIBUTOR_H
