import QtQuick 2.0
import "js/NodesGraphFunctions.js" as NGFunc
import vstApp 1.0

Item {
    id:mainitem

    Flickable {
        id: scroll
        anchors.fill: parent
        contentWidth: 2000; contentHeight: 3000
        boundsBehavior: Flickable.StopAtBounds

        Canvas {
            id: grapheditorcanvas
            anchors.fill: parent
//            onPaint: {

//                function paint_connection(id1, id2) {
//                    var node1 = NGFunc.componentsMap.get(id1)
//                    var node2 = NGFunc.componentsMap.get(id2)

//                    var ctx = getContext("2d")

//                }

//                var ctx = getContext("2d")
//                var rectx = someRect.x + someRect.width/2
//                var recty = someRect.y + someRect.height
//                var rectx2 = someRect2.x + someRect.width/2
//                var recty2 = someRect2.y
//                ctx.strokeStyle = Qt.rgba(0, 0, 0, 1)
//                ctx.lineWidth = 2
//                ctx.reset()
//                grapheditorcanvas.requestPaint()
//                ctx.beginPath()

//                //                ctx.moveTo(20, 20)
//                //                ctx.arc(20, 20, 5, 0, 2*Math.PI, true)
//                //                ctx.moveTo(600, 120)
//                //                ctx.arc(600, 120, 5, 0, 2*Math.PI, true)
//                ctx.moveTo(rectx, recty)
//                ctx.arc(rectx, recty, 5, 0, 2*Math.PI, true)
//                //                ctx.moveTo(120, 120)
//                //                ctx.arc(120, 120, 5, 0, 2*Math.PI, true)
//                ctx.moveTo(rectx, recty)
//                ctx.bezierCurveTo(rectx, recty, rectx, recty + 60, (rectx + rectx2) / 2, (recty + recty2) / 2)
//                ctx.bezierCurveTo((rectx + rectx2) / 2, (recty + recty2) / 2, rectx2, recty2 - 60, rectx2, recty2)
//                ctx.stroke()
//                ctx.closePath()

//            }
        }
    }
    function paint_connection(id1, id2, totrue) {
        var node1 = NGFunc.componentsMap.get(id1)
        var node2 = NGFunc.componentsMap.get(id2)

        var ctx = getContext("2d")
        var rectx = node1.x + node1.width/2
        var recty = node1.y + node1.height
        var rectx2 = node2.x + node2.width/2
        var recty2 = node2.y
        ctx.strokeStyle = Qt.rgba(0, 0, 0, 1)
        ctx.lineWidth = 2
        grapheditorcanvas.requestPaint()
        ctx.beginPath()
        ctx.moveTo(rectx, recty)
        ctx.bezierCurveTo(rectx, recty, rectx, recty + 60, (rectx + rectx2) / 2, (recty + recty2) / 2)
        ctx.bezierCurveTo((rectx + rectx2) / 2, (recty + recty2) / 2, rectx2, recty2 - 60, rectx2, recty2)
        ctx.stroke()
        ctx.closePath()
    }
    function updateCanvas() {
        var ctx = getContext("2d")
        ctx.reset()

        for(let nodeid of NGFunc.componentsMap.keys()) {
            var nodecomponent = NGFunc.componentsMap.get(nodeid)
            if(nodecomponent.isifnode === true) {
                var falsenodeid = nodesGraphContainer.getConnectedNodeId(parceInt(nodeid), false)
                if(falsenodeid !== 0) {
                    paint_connection(nodeid, falsenodeid, false)
                }
            }
            var truenodeid = nodesGraphContainer.getConnectedNodeId(parceInt(nodeid), true)
            if(truenodeid !== 0) {
                paint_connection(nodeid, truenodeid, true)
            }


        }
    }
}


