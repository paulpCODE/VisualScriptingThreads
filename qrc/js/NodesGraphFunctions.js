.import vstApp 1.0 as App
.import QtQml 2.15 as QtQml



function createNode() {
    var nodeIndex
    var component = Qt.createComponent("../Node.qml")
    if(component.status === QtQml.Component.Ready)
        var objcomp = component.createObject(grapheditor.scrollf.contentItem, {x: grapheditor.scrollf.contentX + 100, y:grapheditor.scrollf.contentY + 100})
    switch(nodemenu.currentIndex)  {
    case 0:
        nodeIndex = nodesGraphContainer.createNode(nodesGraphsSettings.currentEditingGraphId, App.NodeEnums.GlobalAssignGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.operationText = "="
        objcomp.cb2visible = true
        objcomp.z = 100

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 1:
        nodeIndex = nodesGraphContainer.createNode(nodesGraphsSettings.currentEditingGraphId, App.NodeEnums.GlobalAssignConst)

        objcomp.nodeindex = nodeIndex
        objcomp.operationText = "="

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 2:
        nodeIndex = nodesGraphContainer.createNode(nodesGraphsSettings.currentEditingGraphId, App.NodeEnums.InputGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isprintorinput = true
        objcomp.operationText = "INPUT "

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 3:
        nodeIndex = nodesGraphContainer.createNode(nodesGraphsSettings.currentEditingGraphId, App.NodeEnums.PrintGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isprintorinput = true
        objcomp.operationText = "PRINT "

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 4:
        nodeIndex = nodesGraphContainer.createNode(nodesGraphsSettings.currentEditingGraphId, App.NodeEnums.IfGlobalEqualGlobal)

        objcomp.nodeindex = nodeIndex
        objcomp.isifnode = true
        objcomp.operationText = "=="

        grapheditor.componentsMap.set(nodeIndex, objcomp)
        break
    case 5:
        nodeIndex = nodesGraphContainer.createNode(nodesGraphsSettings.currentEditingGraphId, App.NodeEnums.IfGlobalLessGlobal)

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

    nodesGraphContainer.deleteNode(nodesGraphsSettings.currentEditingGraphId, parseInt(id))

    grapheditor.clearCanvas()
    grapheditor.updateCanvas()
}

function connectNodes(id1, id2, totrue) {
    if(!grapheditor.componentsMap.has(parseInt(id2))) {
        console.log("connection failed")
        return false
    }

    nodesGraphContainer.connectNodes(nodesGraphsSettings.currentEditingGraphId, parseInt(id1), parseInt(id2), totrue)
    console.log(id1 + " connected to " + id2)
    grapheditor.updateCanvas()
    return true
}

function disconnectNode(id, totrue) {
    nodesGraphContainer.disconnectNode(nodesGraphsSettings.currentEditingGraphId, parseInt(id), totrue)
    console.log(id + " disconnected")
    grapheditor.clearCanvas()
    grapheditor.updateCanvas()
}

function setNodeData(id, leftOpetand, rightOperand) {
    console.log(leftOpetand + rightOperand)
    nodesGraphContainer.setNodeData(nodesGraphsSettings.currentEditingGraphId, id, leftOpetand, rightOperand)
}

function setStartNodeId(id) {
    if(!grapheditor.componentsMap.has(parseInt(id))) {
        console.log("connection failed")
        return false
    }

    nodesGraphContainer.setStartNodeId(nodesGraphsSettings.currentEditingGraphId, parseInt(id))
    return true
}

function switchGraph(graphid) {
    if(grapheditor.graphsMap.has(graphid)) {
        if(grapheditor.graphsMap.get(graphid).size !== 0) {
            grapheditor.componentsMap = new Map(grapheditor.graphsMap.get(graphid))
            for(let object of grapheditor.componentsMap.values()) {
                object.visible = true
            }
            grapheditor.updateCanvas()
            return
        }
    }
    grapheditor.componentsMap.clear()
    instantiateBeginNode()
}

function addGraphToMap(graphid) {
    for(let object of grapheditor.componentsMap.values()) {
        object.visible = false
    }
    if(grapheditor.graphsMap.has(graphid)) {
        grapheditor.graphsMap.delete(graphid)
    }

    grapheditor.graphsMap.set(nodesGraphsSettings.currentEditingGraphId, new Map(grapheditor.componentsMap))
    grapheditor.clearCanvas()
}

function instantiateBeginNode() {
    if(grapheditor.componentsMap.has(0)) {
        return
    }

    var component = Qt.createComponent("../BeginNode.qml")
    if(component.status === QtQml.Component.Ready)
        var objcomp = component.createObject(grapheditor.scrollf.contentItem, {x: 300, y:100})

    grapheditor.componentsMap.set(0, objcomp)
}

function updateCanvas() {
    grapheditor.updateCanvas()
}
