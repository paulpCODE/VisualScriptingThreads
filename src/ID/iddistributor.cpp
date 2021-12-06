#include "iddistributor.h"

IdDistributor::IdDistributor(const unsigned int idLimit) : ID_LIMIT(idLimit)
{}

IdDistributor &IdDistributor::operator=(const IdDistributor &right)
{
    this->m_ids.clear();
    for(int i = 0; i < right.m_ids.size(); i++) {
        this->m_ids.push_back(right.m_ids[i]);
    }
    return *this;
}

unsigned int IdDistributor::getFreeId()
{
    if(m_ids.isEmpty()) {
        addNew();
        return 1;
    }

    for(size_t i = 0; i < m_ids.size(); i++) {
        if(m_ids[i]) {
            m_ids[i] = false;
            return i + 1;
        }
    }

    if(!addNew()) {
        return 0;
    }

    return m_ids.size();

}

void IdDistributor::releaseID(unsigned int idToDelete)
{
    unsigned int idIndex = idToDelete - 1;
    if(idIndex >= m_ids.size()) {
        return;
    }
    if(!m_ids[idIndex]) {
        m_ids[idIndex] = true;
    }
}

bool IdDistributor::addNew()
{
    if(m_ids.size() == ID_LIMIT) {
        return false;
    }

    m_ids.push_back(false);
    return true;
}
