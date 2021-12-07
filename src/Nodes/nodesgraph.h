#ifndef NODESGRAPH_H
#define NODESGRAPH_H
#include <QMap>
#include "nodedata.h"
#include "iddistributor.h"
#include "globalvariablescontainer.h"
#include <QObject>




class NodesGraph : public QObject
{
    Q_OBJECT
private:
    const unsigned int NODESLIMIT;
    const unsigned int m_id;

    unsigned int m_startNodeId;

    IdDistributor * ID;

    QMap<unsigned int, NodeData*> m_nodes;
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
    /*
    #type - type of Node(NodeType enum in NodeData)
    #RETURNS ID OF NEW CREATED NODE.
    */
    Q_INVOKABLE const unsigned int createNode(const NodeEnums::NodeType& type);
    Q_INVOKABLE void deleteNode(unsigned int id);
    /*
    #idfrom - id of Node with out execution pin.
    #idto - id of Node with in execution pin.
    #totrue - if node have ONESIDED connection type -> value of totrue dont have matter.
              if node have DOUBLESIDED connection type -> connect true or false execution pin. Depends on value of totrue.
    */
    Q_INVOKABLE void connectNodes(unsigned int idfrom, unsigned int idto, bool totrue = true);
    /*
    #id - id of Node with out execution pin.
    #totrue - if node have ONESIDED connection type -> value of totrue dont have matter.
              if node have DOUBLESIDED connection type -> disconnect true or false execution pin. Depends on value of totrue.
    */
    Q_INVOKABLE void disconnectNode(unsigned int id, bool totrue = true);
    Q_INVOKABLE NodeEnums::NodeType GetType(unsigned int id) const;
    Q_INVOKABLE const unsigned int GetId() const;
    /*
    #id - Node id.
    #leftOperand - left side before operation(+ - = etc).
    #rightOperand - right side after operation(+ - = etc).
    */
    Q_INVOKABLE void SetNodeData(const unsigned int id, const QString& leftOperand, const QString& rightOperand);
    /*
    #id - Node id.

    Sets start node id. From this node will start the graph execution process(execution() function)
    */
    Q_INVOKABLE void SetStartNodeId(const unsigned int id);
};

#endif // NODESGRAPH_H
