import QtQuick 2.0
import "js/NodesGraphFunctions.js" as NGFunc

Item {
    id: mainitem
    property int startnodeid: 0
    readonly property alias isconnected: truepin.isconnected
    readonly property alias rwidth: node.width
    readonly property alias rheight: node.height

    Rectangle {
        id:node
        width: 130
        height: 70
        border.width: 1

        Rectangle {
            id:toppanel
            height: 20
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            color: "black"

            MouseArea {
                id: mousearea
                width: parent
                anchors.fill: parent
                drag.axis: Drag.XAndYAxis
                drag.target: mainitem
                drag.minimumX: 0
                drag.maximumX: grapheditor.canvas.width - node.width
                drag.minimumY: 0
                drag.maximumY: grapheditor.canvas.height - node.height
                onPositionChanged: {
                    grapheditor.updateCanvas()
                }
            }
        }

        ExecutionPinEditor {
            id: truepin
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            width: 74
            height: 20
            anchors.left: parent.left
            anchors.leftMargin: parent.width / 2 - 10
            connectButton.onClicked: {
                if(!isconnected) {
                    var access = NGFunc.setStartNodeId(idtoconnect)
                    console.log(access)
                    if(access) {
                        isconnected = true
                        startnodeid = parseInt(idtoconnect)
                        NGFunc.updateCanvas()
                    }
                } else {
                    nodesGraphContainer.setStartNodeId(nodesGraphsSettings.currentEditingGraphId, 0)
                    isconnected = false
                    startnodeid = 0
                    NGFunc.updateCanvas()
                }
            }
        }

        Text {
            id: operation
            font.bold: true
            font.pixelSize: 20
            text: "BEGIN"
            anchors.centerIn: parent
        }
    }

}
