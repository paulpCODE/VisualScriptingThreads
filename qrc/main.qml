import QtQuick 2.15
import QtQuick.Window 2.15
import vstApp 1.0
import QtQuick.Controls 2.12
Window {
    id: mainwindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    ListView {
//        id: view1
//        anchors { top: parent.top; left: parent.left; bottom: parent.bottom }
//        width: parent.width / 2
//        spacing: 5

//        delegate: Rectangle {
//            border.color: "black"
//            border.width: 1
//            height: 30
//            width: parent.width
//            Text {
//                id: nameText
//                anchors.centerIn: parent
//                text: modelData
//            }
//        }
//        model: globalVariablesContainer.qstringlistGlobalVariableModel
//    }
//    Control{
//        background: Rectangle{
//            border.color: "black"
//            border.width: 3
//        }

//        id: infoRect
//        padding: 10
//        property string receivedName:""
//        property string receivedValue:""
//        property alias ttext: varName.text
//        x:400
//        //anchors:{ top: parent.top; left: parent.right; bottom: parent.bottom }
//        width: 200
//        height: 50

//        Text {
//            id: varName
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            text:"Var name: " + infoRect.receivedName
//        }
//        Text {
//            id: varValue
//            anchors.left: varName.right
//            anchors.leftMargin: 10
//            text: "Var value: " + infoRect.receivedValue
//        }
//    }
//    Control{
//        background: Rectangle{
//            border.color: "black"
//            border.width: 3
//        }
//        padding: 10

//        x: 400
//        y: 100
//        //anchors:{ top: parent.top; left: parent.right; bottom: parent.bottom }
//        width: 200
//        height: 100

//        Text {
//            id: tex
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            text: "Enter Variable Name "
//        }
//        TextField{
//            id: textInput
//            // property alias inputVarName:
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            anchors.top: tex.bottom
//            anchors.topMargin: 10
//            placeholderText: "input Name"
//            onEditingFinished: {
//                var cppGlobalVariable = globalVariablesContainer.globalVariableByName(text)
//                if(cppGlobalVariable !== null){
//                    infoRect.receivedName = cppGlobalVariable.name
//                    infoRect.receivedValue = cppGlobalVariable.value
//                }
//            }
//        }
//    }
//    Control{
//        id: newVariableRect
//        background: Rectangle{
//            border.color: "black"
//            border.width: 3
//        }
//        padding: 10
//        x:400
//        y: 200
//        //anchors:{ top: parent.top; left: parent.right; bottom: parent.bottom }
//        width: 200
//        height: 150

//        property string receivedNewName:""
//        property string receivedNewValue:""

//        Text {
//            id: title
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            text: "Input data to create new variable "
//        }
//        TextField{
//            id: newName
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            // property alias inputVarName:
//            anchors.top: title.bottom
//            anchors.topMargin: 10
//            placeholderText: "new Name"
//            onEditingFinished: {
//                newVariableRect.receivedNewName = newName.text
//            }
//        }
//        TextField{
//            id: newValue
//            // property alias inputVarName:
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            anchors.top: newName.bottom
//            anchors.topMargin: 10
//            placeholderText: "new Value"
//            validator: IntValidator {bottom: 0; top: 2147483647}
//            onEditingFinished: {
//                newVariableRect.receivedNewValue = newValue.text
//            }
//        }
//        Button{
//            anchors.left: parent.left
//            anchors.leftMargin: 10
//            anchors.top: newValue.bottom
//            anchors.topMargin: 10
//            text: "create new var"
//            onClicked:{
//                if(newVariableRect.receivedNewName!==""){
//                    globalVariablesContainer.changeGlobalVariable("a",newVariableRect.receivedNewName,newVariableRect.receivedNewValue)
//                }
//            }
//        }
//    }
    GraphEditor {
        id: grapheditor
        anchors.fill: parent
    }

    NodeMenu {
        id: nodemenu
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 5
    }


//    Component.onCompleted: {
//        var component = Qt.createComponent("GraphEditor.qml")
//        if(component.status === Component.Ready)
//            var objcomp1 = component.createObject(mainwindow, {x: 100, y:100})
//        var component2 = Qt.createComponent("GraphEditor.qml")
//        if(component2.status === Component.Ready)
//            var objcomp2 = component.createObject(mainwindow, {x: 300, y:300})

//        objcomp1.a = "ALPHA"
//    }

    Node {
        x:100
        y:100
        operationText: "="
    }

//    GlobalVariablesMenu{
//        anchors.top: parent.top
//        anchors.left: parent.left
//        anchors.margins: 50
//    }
//    GlobalVariablesSettings{
//        x:200
//        y:200
//        height: 200
//    }
}

