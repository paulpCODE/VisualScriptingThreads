import QtQuick 2.0

Item {
    id:mainitem
    property int nodeidText: 0

    Rectangle {
        id: toppanel
        anchors.fill: parent
        color: "black"


        Text {
            id: nodeidTextObject
            text: nodeidText
            font.pixelSize: 14
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 2
            color: "white"
        }
    }
}
