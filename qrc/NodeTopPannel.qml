import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id:mainitem
    property int nodeidText: 0
    property alias pdeletebutton: deletebutton

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
        Button {
            id:deletebutton
            height: parent.height - 4
            width: height
            text: "X"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 2
        }
    }
}
