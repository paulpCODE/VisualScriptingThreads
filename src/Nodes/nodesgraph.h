#ifndef NODESGRAPH_H
#define NODESGRAPH_H
#include <QMap>
#include "nodedata.h"
#include "iddistributor.h"
#include "globalvariablescontainer.h"
#include <QObject>
#include <QPair>




class NodesGraph : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString graphName READ graphName WRITE setGraphName NOTIFY graphNameChanged)
private:
    const unsigned int NODESLIMIT;
    const unsigned int m_id;

    unsigned int m_startNodeId;

    IdDistributor * ID;

    QMap<unsigned int, NodeData*> m_nodes;
    QString m_graphName;

public:
    NodesGraph(const unsigned int id);
    ~NodesGraph();

    /*
    #gvcptr - Global Variables Container Pointer.

    Executes all graph automatically.
    This function calls in NodesGraphsContainer in method executeGraph.
    */
    void execute(GlobalVariablesContainer * const gvcptr);
    /*
    #target - new NodesGraph instace(copy of other)
    #other - Copied object

    Use construction
    NodesGraph instance(copyTarget.GetId()
    instance.deepCopy(copyTarget)
    to copy and give new instance of class NodesGraph.
    If ids of two objects not equal -> return empty target without data
    */
    void deepCopy(const NodesGraph& copyTarget);
    NodeEnums::NodeType GetType(unsigned int id) const;
    const unsigned int GetId() const;

    /*
    #type - type of Node(NodeType enum in NodeData)
    #RETURNS ID OF NEW CREATED NODE.
    */

    const unsigned int createNode(const NodeEnums::NodeType& type);
    void deleteNode(unsigned int id);
    /*
    #idfrom - id of Node with out execution pin.
    #idto - id of Node with in execution pin.
    #totrue - if node have ONESIDED connection type -> value of totrue dont have matter.
              if node have DOUBLESIDED connection type -> connect true or false execution pin. Depends on value of totrue.
    */
    void connectNodes(unsigned int idfrom, unsigned int idto, bool totrue = true);
    /*
    #id - id of Node with out execution pin.
    #totrue - if node have ONESIDED connection type -> value of totrue dont have matter.
              if node have DOUBLESIDED connection type -> disconnect true or false execution pin. Depends on value of totrue.
    */
    void disconnectNode(unsigned int id, bool totrue = true);
    /*
    #id - Node id.
    #leftOperand - left side before operation(+ - = etc).
    #rightOperand - right side after operation(+ - = etc).
    */
    void SetNodeData(const unsigned int id, const QString& leftOperand, const QString& rightOperand);

    QPair<QString,QString> GetNodeOperandsData(const unsigned int id) const;

    QString convertToQString();

    /*
    #id - Node id.

    Sets start node id. From this node will start the graph execution process(execution() function)
    */
    void SetStartNodeId(const unsigned int id);
    const unsigned int GetConnectedNodeId(const unsigned int id, bool totrue = true);


    const QString &graphName() const;
    void setGraphName(const QString &newGraphName);
signals:
    void graphNameChanged();

};

#endif // NODESGRAPH_H
