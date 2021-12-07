import QtQuick 2.0


Item {
    id:comp
    property string a: "SOME TEXT"

    Rectangle {
        width: 100
        height: 100
        border.width: 5
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr(a)
        }
    }
}
