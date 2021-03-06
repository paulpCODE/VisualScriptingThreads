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
    Button{
        id:toggleThreadsSettings
        anchors.right: toggleNodesGraphSettings.left
        anchors.top: parent.top
        z: grapheditor.z + 5
        onPressed: {
            threadsSettings.visible?threadsSettings.visible=false:threadsSettings.visible=true
        }
        text: threadsSettings.visible?"hide threads \n settings ":"show threads \n settings "
    }
    ThreadsSettings{
        id:threadsSettings
        z: grapheditor.z + 5
        anchors.right:
        {
            if(nodesGraphsSettings.visible){
                nodesGraphsSettings.left
            }
            else if(globalVariablesSettings.visible){
                globalVariablesSettings.left
            }
            else{
                parent.right
            }
        }
        anchors.top: toggleThreadsSettings.bottom
        anchors.bottom:parent.bottom
        visible: false
    }
    Button{
        id:executeThreads
        anchors.right: toggleThreadsSettings.left
        anchors.top: parent.top
        height: toggleThreadsSettings.height
        z: grapheditor.z + 5
        onPressed: {
            threadManager.runAllThreads();
        }
        text: "Execute code in threads"
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
}

