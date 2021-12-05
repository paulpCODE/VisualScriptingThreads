#include "nodesgraph.h"

NodesGraph::NodesGraph()
{

}

void NodesGraph::execute()
{

}

void NodesGraph::createNode(const NodeType &type)
{

}

void NodesGraph::changeType(unsigned char id, NodeType &type)
{

}

void NodesGraph::deleteNode(unsigned char id)
{

}

void NodesGraph::connectNodes(unsigned char idfrom, unsigned char idto, bool totrue)
{

}

void NodesGraph::disconnectNode(unsigned char id, bool totrue)
{

}

NodeType NodesGraph::GetType(unsigned char id) const
{
    return NodeType::GlobalAssignConst; // #TODO
}
