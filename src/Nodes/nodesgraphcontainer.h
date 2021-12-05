#ifndef NODESGRAPHCONTAINER_H
#define NODESGRAPHCONTAINER_H


#include "globalvariablescontainer.h"
#include "nodesgraph.h"



//Nodes Graph
class NodesGraphContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<NodesGraph> graphsList READ graphsList CONSTANT)
private:
    const unsigned int GRAPHSLIMIT;

    IdDistributor * ID;// #TODO rework
    const GlobalVariablesContainer * m_gvcptr;

    QList<NodesGraph*> m_graphsList;
public:
    NodesGraphContainer(const GlobalVariablesContainer * const gvcptr);
    ~NodesGraphContainer(); //set m_gvcptr to nullptr(no delete)

    QQmlListProperty<NodesGraph> graphsList();

public slots:
    const unsigned int addGraph();
    void deleteGraph(const unsigned int id);
    NodesGraph* GetGraph(const unsigned int id) const;
};

#endif // NODESGRAPHCONTAINER_H
