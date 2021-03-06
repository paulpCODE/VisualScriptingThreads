import QtQuick 2.0
import "js/NodesGraphFunctions.js" as NGFunc
import vstApp 1.0

Item {
    id:mainitem
    property alias canvas: grapheditorcanvas
    property alias scrollf: scroll
    property var graphsMap: new Map()
    property var componentsMap: new Map()

    Flickable {
        id: scroll
        width: mainwindow.width
        height: mainwindow.height
        anchors.fill: parent
        contentWidth: 2000
        contentHeight: 3000
        boundsBehavior: Flickable.StopAtBounds

        Canvas {
            id: grapheditorcanvas
            width: parent.width
            height: parent.height
        }

        Component.onCompleted: {
            NGFunc.instantiateBeginNode()
        }


    }
    function paint_connection(id1, id2, totrue, isifnode) {
        var node1 = componentsMap.get(id1)
        var node2 = componentsMap.get(id2)
        var rectx = 0
        var recty = 0
        if(isifnode === true) {
            if(totrue) {
                rectx = node1.x + node1.rwidth - 64
            } else {
                rectx = node1.x + 64
            }
        } else {
            rectx = node1.x + node1.rwidth/2
        }

        recty = node1.y + node1.rheight
        var rectx2 = node2.x + node2.rwidth/2
        var recty2 = node2.y

        var ctx = grapheditorcanvas.getContext("2d")
        ctx.strokeStyle = Qt.rgba(0, 0, 0, 1)
        ctx.lineWidth = 1
        ctx.beginPath()
        //ctx.moveTo(node1.x, node1.y)
        //ctx.arc(node1.x, node1.y, 5, 0, 2*Math.PI, true)
        ctx.moveTo(rectx, recty)
        ctx.bezierCurveTo(rectx, recty, rectx, recty + 30, (rectx + rectx2) / 2, (recty + recty2) / 2)
        ctx.bezierCurveTo((rectx + rectx2) / 2, (recty + recty2) / 2, rectx2, recty2 - 30, rectx2, recty2)
        ctx.stroke()
        ctx.closePath()
    }
//    function paint_connection_begin(id) {

//        var node = componentsMap.get(id)
//        var rectx = begin.x + begin.rwidth / 2
//        var recty = begin.y + begin.rheight
//        var rectx2 = node.x + node.rwidth/2
//        var recty2 = node.y

//        var ctx = grapheditorcanvas.getContext("2d")
//        ctx.strokeStyle = Qt.rgba(0, 0, 0, 1)
//        ctx.lineWidth = 1
//        ctx.beginPath()
//        //ctx.moveTo(node1.x, node1.y)
//        //ctx.arc(node1.x, node1.y, 5, 0, 2*Math.PI, true)
//        ctx.moveTo(rectx, recty)
//        ctx.bezierCurveTo(rectx, recty, rectx, recty + 30, (rectx + rectx2) / 2, (recty + recty2) / 2)
//        ctx.bezierCurveTo((rectx + rectx2) / 2, (recty + recty2) / 2, rectx2, recty2 - 30, rectx2, recty2)
//        ctx.stroke()
//        ctx.closePath()
//    }
    function updateCanvas() {
        grapheditorcanvas.requestPaint()
        var ctx = grapheditorcanvas.getContext("2d")
        ctx.reset()

        if(componentsMap.has(0)) {
            if(componentsMap.get(0).isconnected) {
                paint_connection(0, componentsMap.get(0).startnodeid)
            }
        }

        for(let nodeid of componentsMap.keys()) {
            if(nodeid === 0) {
                continue
            }

            var nodecomponent = componentsMap.get(nodeid)
            if(nodecomponent.isifnode === true) {
                var falsenodeid = nodesGraphContainer.getConnectedNodeId(nodesGraphsSettings.currentEditingGraphId, parseInt(nodeid), false)
                if(falsenodeid !== 0) {
                    paint_connection(nodeid, falsenodeid, false, nodecomponent.isifnode)
                }
            }
            var truenodeid = nodesGraphContainer.getConnectedNodeId(nodesGraphsSettings.currentEditingGraphId, parseInt(nodeid), true)
            if(truenodeid !== 0) {
                paint_connection(nodeid, truenodeid, true, nodecomponent.isifnode)
            }
        }

    }
    function clearCanvas() {
        grapheditorcanvas.requestPaint()
        var ctx = grapheditorcanvas.getContext("2d")
        ctx.reset()
        ctx.clearRect(Qt.rect(0,0,grapheditorcanvas.width, grapheditorcanvas.height))
    }

}


