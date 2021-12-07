#ifndef NODESGRAPHCONTAINER_H
#define NODESGRAPHCONTAINER_H


#include "globalvariablescontainer.h"
#include "nodesgraph.h"
#include <QPair>



//Nodes Graph
class NodesGraphContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList qstringListNodesGraphContainerModel READ qstringListNodesGraphContainerModel WRITE setQstringListNodesGraphContainerModel NOTIFY qstringListNodesGraphContainerModelChanged)
private:
    const unsigned int GRAPHSLIMIT;

    IdDistributor * ID;// #TODO rework
    GlobalVariablesContainer * m_gvcptr;

    QList<NodesGraph*> m_graphsList;
    QStringList m_qstringListNodesGraphContainerModel;

public:
    NodesGraphContainer(GlobalVariablesContainer * const gvcptr);
    ~NodesGraphContainer(); //set m_gvcptr to nullptr(no delete)

    void updateQstringListNodesGraphContainerModel();
    const QList<NodesGraph*> *GraphsList() const;
    void executeGraph(const unsigned int id);

    Q_INVOKABLE const unsigned int addGraph();
    Q_INVOKABLE void deleteGraph(const unsigned int id);
    Q_INVOKABLE NodesGraph* GetGraph(const unsigned int id) const;


    // Check nodesgraph.h to read documentation
    Q_INVOKABLE const unsigned int createNode(const unsigned int graphid, const NodeEnums::NodeType& type);
    Q_INVOKABLE void deleteNode(const unsigned int graphid, unsigned int id);
    Q_INVOKABLE void connectNodes(const unsigned int graphid, unsigned int idfrom, unsigned int idto, bool totrue = true);
    Q_INVOKABLE void disconnectNode(const unsigned int graphid, unsigned int id, bool totrue = true);
    Q_INVOKABLE void SetNodeData(const unsigned int graphid, const unsigned int id, const QString& leftOperand, const QString& rightOperand);
    Q_INVOKABLE QPair<QString,QString> GetNodeOperandsData(const unsigned int graphid, const unsigned int id);
    Q_INVOKABLE void SetStartNodeId(const unsigned int graphid, const unsigned int id);
    Q_INVOKABLE void renameGraphById(const unsigned int graphid, const QString& newName);
    //If need to access graphid by choosing current index in qml graphmenu
    Q_INVOKABLE int getGraphIdByModelIndex(const unsigned int modelIndex) const;

    const QStringList &qstringListNodesGraphContainerModel() const;
    void setQstringListNodesGraphContainerModel(const QStringList &newQstringListNodesGraphContainerModel);

signals:
    void noLongerUsingGlobalVariable(const QString & variableName);
    void usingNewGlobalVariable(const QString & variableName);
    void qstringListNodesGraphContainerModelChanged();
    void nodesGraphContainerDataChanged();

};

#endif // NODESGRAPHCONTAINER_H
