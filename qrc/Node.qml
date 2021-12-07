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
