#ifndef NODESGRAPHCONTAINER_H
#define NODESGRAPHCONTAINER_H


#include "globalvariablescontainer.h"
#include "nodesgraph.h"



//Nodes Graph
class NodesGraphContainer : public QObject
{
    Q_OBJECT
private:
    const unsigned int GRAPHSLIMIT;

    IdDistributor * ID;// #TODO rework
    GlobalVariablesContainer * m_gvcptr;

    QList<NodesGraph*> m_graphsList;
public:
    NodesGraphContainer(GlobalVariablesContainer * const gvcptr);
    ~NodesGraphContainer(); //set m_gvcptr to nullptr(no delete)

    const QList<NodesGraph*> *GraphsList() const;
    void executeGraph(const unsigned int id);

    Q_INVOKABLE const unsigned int addGraph();
    Q_INVOKABLE void deleteGraph(const unsigned int id);
    Q_INVOKABLE NodesGraph* GetGraph(const unsigned int id) const;
};

#endif // NODESGRAPHCONTAINER_H
