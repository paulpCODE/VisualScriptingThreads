import QtQuick 2.15
import QtQuick.Window 2.15
import vstApp 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ListView {
            id: view1
            anchors { top: parent.top; left: parent.left; bottom: parent.bottom }
            width: parent.width / 2
            spacing: 5

            delegate: Item {
                height: 30
                width: parent.width

                Text { text: name }

                MouseArea {
                    anchors.fill: parent
                    onClicked: model.name += "1";
                }
            }
            model: globalVariablesContainer.globalVariables
        }
}
