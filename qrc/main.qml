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
        z: grapheditor.z + 5
        onPressed: {
            globalVariablesSettings.visible?globalVariablesSettings.visible=false:globalVariablesSettings.visible=true
        }
        text: globalVariablesSettings.visible?"hide variables \n settings ":"show variables \n settings "
    }
    GlobalVariablesSettings{
        id:globalVariablesSettings
        z: grapheditor.z + 5
        anchors.right: parent.right
        anchors.top: toggleVariablesSettings.bottom
        anchors.bottom:parent.bottom
        visible: false
    }

    Button{
        id:toggleNodesGraphSettings
        anchors.right: toggleVariablesSettings.left
        anchors.top: parent.top
        z: grapheditor.z + 5
        onPressed: {
            nodesGraphsSettings.visible?nodesGraphsSettings.visible=false:nodesGraphsSettings.visible=true
        }
        text: nodesGraphsSettings.visible?"hide graphs \n settings ":"show graphs \n settings "
    }
    NodesGraphsSettings{
        id:nodesGraphsSettings
        z: grapheditor.z + 5
        anchors.right:globalVariablesSettings.visible? globalVariablesSettings.left:parent.right
        anchors.top: toggleNodesGraphSettings.bottom
        anchors.bottom:parent.bottom
        visible: false
    }

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


}

