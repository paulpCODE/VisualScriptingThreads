import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id:mainitem

    Rectangle {
        anchors.fill: parent
        color: "#dddec3"

        Rectangle {
            anchors.top: parent.top
            width: parent.width
            color:"#c6c7af"

            Text {
                text: qsTr("V1 = V2")
                anchors.left: parent.left
                anchors.leftMargin: 5
            }

            Button {
                text: "+"
                font.pixelSize: 15
                width: 20
                height: 20
                anchors.right: parent.right
            }
        }
    }
}
