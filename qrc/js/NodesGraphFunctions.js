.import vstApp 1.0 as App
.import QtQml 2.15 as QtQml



function createNode() {
    var nodeIndex
    var component = Qt.createComponent("../Node.qml")
    if(component.status === QtQml.Component.Ready)
        var objcomp = component.createObject(grapheditor.scrollf.contentItem, {x: grapheditor.scrollf.contentX + 100, y:grapheditor.scrollf.contentY + 100})
    switch(nodemenu.currentIndex)  {
    case 0:
        nodeIndex = nodesGraphContainer.createNode(1, App.NodeEnums.GlobalAssignGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.operationText = "="
        objcomp.cb2visible = true
        objcomp.z = 100

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 1:
        nodeIndex = nodesGraphContainer.createNode(1, App.NodeEnums.GlobalAssignConst)

        objcomp.nodeindex = nodeIndex
        objcomp.operationText = "="

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 2:
        nodeIndex = nodesGraphContainer.createNode(1, App.NodeEnums.InputGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isprintorinput = true
        objcomp.operationText = "INPUT "

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 3:
        nodeIndex = nodesGraphContainer.createNode(1, App.NodeEnums.PrintGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isprintorinput = true
        objcomp.operationText = "PRINT "

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 4:
        nodeIndex = nodesGraphContainer.createNode(1, App.NodeEnums.IfGlobalEqualGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isifnode = true
        objcomp.operationText = "=="

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 5:
        nodeIndex = nodesGraphContainer.createNode(1, App.NodeEnums.IfGlobalLessGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isifnode = true
        objcomp.operationText = "<"

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    }
}

function deleteNode(id) {
    grapheditor.componentsMap.get(id).destroy()
    grapheditor.componentsMap.delete(id)

    nodesGraphContainer.deleteNode(1, parseInt(id))

    grapheditor.clearCanvas()
    grapheditor.updateCanvas()
}

function connectNodes(id1, id2, totrue) {
    if(!grapheditor.componentsMap.has(parseInt(id2))) {
        console.log("connection failed")
        return false
    }

    nodesGraphContainer.connectNodes(1, parseInt(id1), parseInt(id2), totrue)
    console.log(id1 + " connected to " + id2)
    grapheditor.updateCanvas()
    return true
}

function disconnectNode(id, totrue) {
    nodesGraphContainer.disconnectNode(1, parseInt(id), totrue)
    console.log(id + " disconnected")
    grapheditor.clearCanvas()
    grapheditor.updateCanvas()
}

function setNodeData(id, leftOpetand, rightOperand) {
    nodesGraphContainer.setNodeData(1, id, leftOpetand, rightOperand)
}

function setStartNodeId(id) {
    if(!grapheditor.componentsMap.has(parseInt(id))) {
        console.log("connection failed")
        return false
    }

    nodesGraphContainer.setStartNodeId(1, parseInt(id))
    return true
}
