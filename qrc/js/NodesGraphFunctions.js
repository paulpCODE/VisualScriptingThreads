

let componentsMap = new Map()
let connectionsMap = new Map()

function createNode() {
    var nodeIndex
    var component = Qt.createComponent("../Node.qml")
    if(component.status === Component.Ready)
        var objcomp = component.createObject(grapheditor, {x: 100, y:100})
    switch(nodemenu.currentIndex)  {
    case 0:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.GlobalAssignGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.operationText = "="
        objcomp.cb2visible = true

        componentsMap.set(nodeIndex, objcomp)
        break
    case 1:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.GlobalAssignConst)

        objcomp.nodeindex = nodeIndex
        objcomp.operationText = "="

        componentsMap.set(nodeIndex, objcomp)
        break
    case 2:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.InputGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isprintorinput = true
        objcomp.operationText = "INPUT "

        componentsMap.set(nodeIndex, objcomp)
        break
    case 3:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.PrintGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isprintorinput = true
        objcomp.operationText = "PRINT "

        componentsMap.set(nodeIndex, objcomp)
        break
    case 4:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.IfGlobalEqualGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isifnode = true
        objcomp.operationText = "=="

        componentsMap.set(nodeIndex, objcomp)
        break
    case 5:
        nodeIndex = nodesGraphContainer.createNode(1, nodeEnums.IfGlobalLessGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isifnode = true
        objcomp.operationText = "<"

        componentsMap.set(nodeIndex, objcomp)
        break
    }
}

function deleteNode(id) {

}

function connectNodes(id1, id2) {

}

function disconnectNode(id) {

}

function setNodeData(id, leftOpetand, rightOperand) {

}

function setStartNodeId(id) {

}
