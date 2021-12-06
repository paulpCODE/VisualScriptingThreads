#include "nodesgraphcontainer.h"

NodesGraphContainer::NodesGraphContainer(const GlobalVariablesContainer * const gvcptr) : GRAPHSLIMIT(100)
{
    m_gvcptr = gvcptr;
}

NodesGraphContainer::~NodesGraphContainer()
{
    m_gvcptr = nullptr;
    delete ID;
}

QQmlListProperty<NodesGraph> NodesGraphContainer::graphsList()
{
    return QQmlListProperty<NodesGraph>(this, &m_graphsList);
}

const QList<NodesGraph *> *NodesGraphContainer::GraphsList() const
{
    return &m_graphsList;
}



const unsigned int NodesGraphContainer::addGraph()
{
    unsigned int idForGraph = ID->getFreeId();
    if(idForGraph == 0) {
        qDebug("GRAPHS LIMIT!");
        return idForGraph;
    }
    m_graphsList.append(new NodesGraph(idForGraph));
    return idForGraph;
}

void NodesGraphContainer::deleteGraph(const unsigned int id)
{
    QMutableListIterator<NodesGraph*> i(m_graphsList);
    while (i.hasNext()) {
        if (i.next()->GetId() == id)
            i.next()->deleteLater();
            i.remove();
        return;
    }
    qDebug("DONT EXIST GRAPH TO DELETE");
}

NodesGraph *NodesGraphContainer::GetGraph(const unsigned int id) const
{
    for(auto &i : m_graphsList) {
        if(i->GetId() == id) {
            return i;
        }
    }
    qDebug("DONT EXIST GRAPH. RETURN INCORRECT.");
    return m_graphsList.first();
}
