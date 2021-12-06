import QtQuick 2.15
import QtQuick.Window 2.15
import vstApp 1.0
import QtQuick.Controls 2.12
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
            height: 100
            width: parent.width

            Text {
                id: nameText
                text: model.name
            }
            Text {
                anchors.left: nameText.right
                id: nameText2
                text: value
            }



            MouseArea {
                anchors.fill: parent
                onClicked: model.name += "1";
            }

        }
        model: globalVariablesContainer.globalVariables
    }
    Rectangle{
        id: infoRect
        property string receivedName:" "
        property string receivedValue:" "
        property alias ttext: varName.text
        border.color: "black"
        border.width: 3
        x:400
        //anchors:{ top: parent.top; left: parent.right; bottom: parent.bottom }
        width: 200
        height: 50

        Text {
            id: varName
            text:"Var name: " + infoRect.receivedName
        }
        Text {
            id: varValue
            anchors.left: varName.right
            anchors.leftMargin: 10
            text: "Var value: " + infoRect.receivedValue
        }
    }
    Rectangle{
        border.color: "blue"
        border.width: 3
        x:400
        y: 100
        //anchors:{ top: parent.top; left: parent.right; bottom: parent.bottom }
        width: 200
        height: 100

        Text {
            id: tex

            text: "Enter inputVariable Name "
        }
        TextField{
            id: textInput
           // property alias inputVarName:
            anchors.top: tex.bottom
            anchors.topMargin: 10
            placeholderText: "input Name"
            onEditingFinished: {
                var cppGlobalVariable = globalVariablesContainer.globalVariableByName(text)
                if(cppGlobalVariable !== null){
                     infoRect.receivedName = cppGlobalVariable.name
                     infoRect.receivedValue = cppGlobalVariable.value
                }
            }
        }
    }

}

