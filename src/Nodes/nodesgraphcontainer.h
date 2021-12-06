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
    GlobalVariablesContainer * m_gvcptr;

    QList<NodesGraph*> m_graphsList;
public:
    NodesGraphContainer(GlobalVariablesContainer * const gvcptr);
    ~NodesGraphContainer(); //set m_gvcptr to nullptr(no delete)

    QQmlListProperty<NodesGraph> graphsList();
    const QList<NodesGraph*> *GraphsList() const;
    void executeGraph(const unsigned int id);
public slots:
    const unsigned int addGraph();
    void deleteGraph(const unsigned int id);
    NodesGraph* GetGraph(const unsigned int id) const;
};

#endif // NODESGRAPHCONTAINER_H
