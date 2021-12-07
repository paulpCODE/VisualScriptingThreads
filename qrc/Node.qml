import QtQuick 2.0
import vstApp 1.0
import QtQuick.Controls 2.15

Item {
    id: mainitem
    property int nodeindex: 0
    property alias operationText: operation.text
    property bool isifnode: false
    property bool isprintorinput: false
    property bool cb2visible: false

    Rectangle {
        id:node
        width: {
            if(isifnode) {
                return ifnodetext.width + operation.width + 180
            }
            if(isprintorinput) {
                return operation.width + 100
            }
            return operation.width + 180
        }

        height: 80
        border.width: 1

        NodeTopPannel {
            id:nodetoppanel
            height: 20
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            nodeidText: nodeindex
            MouseArea {
                id: mousearea
                anchors.fill: parent
                drag.axis: Drag.XAndYAxis
                drag.target: mainitem
                drag.minimumX: 0
                drag.maximumX: mainitem.parent.width
                drag.minimumY: 0
                drag.maximumY: mainitem.parent.height
            }
        }

        ExecutionPinEditor {
            id: truepin
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            width: 74
            height: 20
            anchors.left: {
                if(!isifnode) {
                    return parent.left
                }
            }
            anchors.leftMargin: {
                if(!isifnode) {
                    return parent.width / 2 - 10
                }
            }
            anchors.right: {
                if(isifnode) {
                    return parent.right
                }
            }
            anchors.rightMargin: {
                if(isifnode) {
                    return 2
                }
            }
        }
        ExecutionPinEditor {
            id: pintofalse
            reverce: true
            width: 74
            height: 20

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            anchors.left: parent.left
            anchors.leftMargin: 56
            visible: {
                if(isifnode) {
                    return true
                }
                return false
            }
        }







        ComboBox {
            id: cb1
            width: 80
            height: 20
            model: ["BANANA", "MONKE"]
            anchors.left: {
                if(isprintorinput) {
                    return operation.right
                }
                if(isifnode) {
                    return ifnodetext.right
                }
                return parent.left
            }

            anchors.leftMargin: {
                if(isprintorinput || isifnode) {
                    return 0
                }
                return 10
            }
            anchors.verticalCenter: parent.verticalCenter
        }

        ComboBox {
            id: cb2
            width: 80
            height: 20
            model: ["BANANA", "MONKE"]
            anchors.left: operation.right
            anchors.verticalCenter: parent.verticalCenter
            visible: cb2visible
        }

        TextField {
            width: 80
            height: 20
            anchors.left: operation.right
            anchors.verticalCenter: parent.verticalCenter
            visible: {
                if(isprintorinput) {
                    return false
                }
                if(cb2visible) {
                    return false
                }
                return true
            }
        }
        Text {
            id: ifnodetext
            text: qsTr("IF")
            anchors.left: parent.left
            anchors.leftMargin: 10
            visible: {
                if(isifnode) {
                    return true
                }
                return false
            }
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 16
        }
        Text {
            id: operation
            anchors.left: {
                if(isprintorinput) {
                    return parent.left
                }
                return cb1.right
            }
            anchors.leftMargin: {
                if(isprintorinput) {
                    return 10
                }
                return 0
            }
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
        }
    }
}
