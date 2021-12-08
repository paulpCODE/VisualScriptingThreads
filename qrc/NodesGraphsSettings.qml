import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import vstApp 1.0
import "js/NodesGraphFunctions.js" as NGFunc
Item {
    id:mainrect
    property int currentEditingGraphId:1
    height: 600
    width: 350

    onCurrentEditingGraphIdChanged: {
        NGFunc.switchGraph(currentEditingGraphId)
    }

    Rectangle {
        id:listOfGraphsHeader
        anchors.left: parent.left
        anchors.top: parent.top
        color: "#C0C0C0"
        border.color: "black"
        border.width: 1
        height: 30
        width: listOfGraphs.width
        Text {
            id: headerText
            anchors.centerIn: parent
            text: "Graphs"
        }
    }
    ListView{
        id: listOfGraphs
        anchors.top: listOfGraphsHeader.bottom
        anchors.right: functionsArea.left
        width: parent.width - functionsArea.width
        height: functionsArea.height
        flickableDirection: Flickable.VerticalFlick
        clip: true
        model: nodesGraphContainer.qstringListNodesGraphContainerModel

        delegate:  Rectangle {
            border.color: "black"
            border.width: 1
            height: 30
            width: listOfGraphs.width
            Text {
                id: nameText
                anchors.centerIn: parent
                text: modelData
            }
        }
        ScrollBar.vertical: ScrollBar {
            active: true
        }


    }
    Rectangle{
        id:functionsAreaHeader
        anchors.top: parent.top
        anchors.right: parent.right
        color: "#C0C0C0"
        border.color: "black"
        border.width: 1

        height: 30
        width: functionsArea.width
        Text {
            id: functionsAreaHeaderText

            anchors.centerIn: parent
            text: "Options"
        }
    }
    Flickable {
        id:functionsArea
        clip: true
        anchors.top: functionsAreaHeader.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 200
        ScrollBar.vertical: ScrollBar { }
        contentHeight: addGraphRect.height + deleteGraphrect.height + renameGraphrect.height
        Rectangle{
            id:curEditGraphRect
            width: parent.width
            height: titleEditGraphrect.height + graphtoEditMenu.height + changeEditGraphRect.height + 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 1
            border.color: "black"
            border.width: 1
            Text {
                id: titleEditGraphrect
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("You are now \m editing graph: ")
            }
            NodesGraphMenu{
                id: graphtoEditMenu
                anchors.top: titleEditGraphrect.bottom
                width: parent.width - 10
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
            }
            Button{
                id: changeEditGraphRect
                anchors.top: graphtoEditMenu.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
                width: parent.width
                text: "Change graph to edit"
                onClicked:{
                    NGFunc.addGraphToMap(currentEditingGraphId)
                    var id = nodesGraphContainer.getGraphIdByModelIndex(graphtoEditMenu.currentIndex)
                    mainrect.currentEditingGraphId = id;
                }
            }
        }
        Rectangle{
            id:addGraphRect
            property string nameToCreate: ""
            width: parent.width
            height: titleaddGraphRect.height + nameToAdd.height + addGraphButton.height  + addGraphButton10.height + 25
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: curEditGraphRect.bottom
            anchors.topMargin: 1
            border.color: "black"
            border.width: 1


            Text {
                id: titleaddGraphRect
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("Add graph")
            }


            TextField{
                id: nameToAdd
                anchors.top: titleaddGraphRect.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                placeholderText: "Name of new graph"
                onEditingFinished: {
                    addGraphRect.nameToCreate = nameToAdd.text
                }
            }

            Button{
                id: addGraphButton
                anchors.top: nameToAdd.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width
                text: "Add graph"
                onClicked:{
                    nodesGraphContainer.addGraph(addGraphRect.nameToCreate);
                }
            }
            Button{
                id: addGraphButton10
                anchors.top: addGraphButton.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width
                text: "Add 10 graphs"
                onClicked:{
                    for(var i =0;i<10;i++){
                        nodesGraphContainer.addGraph(addGraphRect.nameToCreate);
                    }
                }
            }
        }
        Rectangle{
            id:deleteGraphrect
            width: parent.width
            height: titleDeleteGraphrect.height + graphtoDeleteMenu.height + deleteGraphButton.height + 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: addGraphRect.bottom
            anchors.topMargin: 1
            border.color: "black"
            border.width: 1


            Text {
                id: titleDeleteGraphrect
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("Choose graph to delete")
            }


            NodesGraphMenu{
                id: graphtoDeleteMenu
                anchors.top: titleDeleteGraphrect.bottom
                width: parent.width - 10
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10

            }
            Button{
                id: deleteGraphButton
                anchors.top: graphtoDeleteMenu.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
                width: parent.width
                text: "delete choosen graph"
                onClicked:{
                    var id = nodesGraphContainer.getGraphIdByModelIndex(graphtoDeleteMenu.currentIndex)
                    nodesGraphContainer.deleteGraph(id) ;
                }
            }
        }
        Rectangle{
            id:renameGraphrect
            property string renameName: ""
            width: parent.width
            height: titleRenameGraphrect.height + graphtoRenameMenu.height + nameToRename.height + renameGraphButton.height +35
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: deleteGraphrect.bottom
            anchors.topMargin: 1
            border.color: "black"
            border.width: 1


            Text {
                id: titleRenameGraphrect
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("Choose graph to rename")
            }


            NodesGraphMenu{
                id: graphtoRenameMenu
                anchors.top: titleRenameGraphrect.bottom
                width: parent.width - 10
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
            }

            TextField{
                id: nameToRename
                anchors.top: graphtoRenameMenu.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                placeholderText: "new name of graph"
                onEditingFinished: {
                    renameGraphrect.renameName = nameToRename.text
                }
            }
            Button{
                id: renameGraphButton
                anchors.top: nameToRename.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
                width: parent.width
                text: "rename choosen graph"
                onClicked:{
                    var id = nodesGraphContainer.getGraphIdByModelIndex(graphtoRenameMenu.currentIndex)
                    nodesGraphContainer.renameGraphById(id,renameGraphrect.renameName) ;
                }
            }
        }

    }
}


