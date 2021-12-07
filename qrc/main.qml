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

    Button{
        id:toggleVariablesSettings
        anchors.right: parent.right
        anchors.top: parent.top

        onPressed: {
            globalVariablesSettings.visible==true?globalVariablesSettings.visible=false:globalVariablesSettings.visible=true
        }
        text: globalVariablesSettings.visible==true?"hide variables \n redactor ":"show variables \n redactor "
    }
    GlobalVariablesSettings{
        id:globalVariablesSettings

        anchors.right: parent.right
        anchors.top: toggleVariablesSettings.bottom
        anchors.bottom:parent.bottom
        visible: false
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

    GlobalVariablesMenu{
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 50
    }

}

