

let componentsMap = new Map()

function createNode() {
    var nodeIndex
    switch(nodemenu.currentIndex)  {
    case 0:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.GlobalAssignGlobal)
        componentsMap.set(nodeIndex, "ABOBA")
        break
    case 1:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.GlobalAssignConst)
        break
    case 2:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.InputGlobal)
        break
    case 3:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.PrintGlobal)
        break
    case 4:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.IfGlobalEqualGlobal)
        break
    case 5:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.IfGlobalLessGlobal)
        break
    }
}
