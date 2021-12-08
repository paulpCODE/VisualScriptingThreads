import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id:mainitem
    property bool reverce: false
    property bool isconnected: false
    property alias connectButton: connectToNodeIDButton
    property alias idtoconnect: connectToNodeIDField.text

    Rectangle {
        id:pinrec
        width: 20
        height: 20
        Image {
            id: pinicon
            source: "Image/pin.png"
            anchors.fill: parent
            sourceSize.width: width*Screen.devicePixelRatio
            sourceSize.height: height*Screen.devicePixelRatio

        }
    }
    TextField {
        id: connectToNodeIDField
        width: 30
        height: 20
        font.pixelSize: 16
        anchors.left:  {
            if(!reverce) {
                return pinrec.right
            }
        }
        anchors.right: {
            if(reverce) {
                return pinrec.left
            }
        }

        anchors.margins: 2
        validator: IntValidator {bottom: 1; top: 100}
    }
    Button {
        id: connectToNodeIDButton
        width: 20
        height: 20
        font.pixelSize: 16
        text: "+"
        anchors.left:  {
            if(!reverce) {
                return connectToNodeIDField.right
            }
        }
        anchors.right: {
            if(reverce) {
                return connectToNodeIDField.left
            }
        }
        anchors.margins: 2

    }

    states: [
        State {
            name: "disconnected"
            when: !isconnected
            PropertyChanges {
                target: connectToNodeIDField
                visible:true
            }
            PropertyChanges {
                target: connectToNodeIDButton
                text: "+"
                anchors.left:  {
                    if(!reverce) {
                        return connectToNodeIDField.right
                    }
                }
                anchors.right: {
                    if(reverce) {
                        return connectToNodeIDField.left
                    }
                }
            }
        },
        State {
            name: "connected"
            when: isconnected
            PropertyChanges {
                target: connectToNodeIDField
                visible:false
            }
            PropertyChanges {
                target: connectToNodeIDButton
                text: "-"
                anchors.left:  {
                    if(!reverce) {
                        return pinrec.right
                    }
                }
                anchors.right: {
                    if(reverce) {
                        return pinrec.left
                    }
                }
            }
        }
    ]
}
