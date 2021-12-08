import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import vstApp 1.0
Item {
    height: 600
    width: 400
    Rectangle {
        id:listOfThreadsHeader
        anchors.left: parent.left
        anchors.top: parent.top
        color: "#C0C0C0"
        border.color: "black"
        border.width: 1
        height: 30
        width: listOfThreads.width
        Text {
            id: headerText
            anchors.centerIn: parent
            text: "Threads"
        }
    }
    ListView{
        id: listOfThreads
        anchors.top: listOfThreadsHeader.bottom
        anchors.right: functionsArea.left
        width: parent.width - functionsArea.width
        height: functionsArea.height
        flickableDirection: Flickable.VerticalFlick
        clip: true
        model: threadManager.qstringlistThreadsModel

        delegate:  Rectangle {
            border.color: "black"
            border.width: 1
            height: 30
            width: listOfThreads.width
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
        contentHeight: addGraphRect.height + deleteGraphrect.height + asignRect.height
        Rectangle{
            id:addGraphRect
            property int amountToCreate: 1
            width: parent.width
            height: titleaddGraphRect.height + amountOfThreads.height + addGraphButton.height + 25
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
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
                text: qsTr("Add Threads")
            }

            TextField{
                id: amountOfThreads
                anchors.top: titleaddGraphRect.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width - 10
                placeholderText: "How many threads to add"
                validator: IntValidator {bottom: 0; top: 100}
                onEditingFinished: {
                    if (amountOfThreads.text!==""){
                        addGraphRect.amountToCreate = amountOfThreads.text
                    }
                }
            }

            Button{
                id: addGraphButton
                anchors.top: amountOfThreads.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width
                text: "Add thread(s)"
                onClicked:{
                    threadManager.addThread(addGraphRect.amountToCreate);
                }
            }
        }
        Rectangle{
            id:deleteGraphrect
            property int numberToDelete: 1
            width: parent.width
            height: titleDeleteGraphrect.height + amountOfThreadsToDelete.height + deleteGraphButton.height + 30
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
                text: qsTr("Delete Threads")
            }

            TextField{
                id: amountOfThreadsToDelete
                anchors.top: titleDeleteGraphrect.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width - 10
                placeholderText: "How many threads to delete"
                validator: IntValidator {bottom: 0; top: 100}
                onEditingFinished: {
                    if (amountOfThreadsToDelete.text!==""){
                        deleteGraphrect.numberToDelete = amountOfThreadsToDelete.text
                    }
                }
            }

            Button{
                id: deleteGraphButton
                anchors.top: amountOfThreadsToDelete.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
                width: parent.width
                text: "delete thread(s)"
                onClicked:{
                    for(var i =0;i<deleteGraphrect.numberToDelete;i++){
                        threadManager.popBackThread();
                    }
                }
            }
        }
        Rectangle{
            id:asignRect
            width: parent.width
            height: titleRenameGraphrect.height + graphtoRenameMenu.height + titleRenameGraphrect1.height + threadsMenu.height + renameGraphButton.height +40
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
                text: qsTr("Asign graph :")
            }
            NodesGraphMenu{
                id: graphtoRenameMenu
                anchors.top: titleRenameGraphrect.bottom
                width: parent.width - 10
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
            }
            Text {
                id: titleRenameGraphrect1
                anchors.top: graphtoRenameMenu.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("to thread :")
            }
            ThreadsMenu{
                id: threadsMenu
                anchors.top: titleRenameGraphrect1.bottom
                width: parent.width - 10
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
            }
            Button{
                id: renameGraphButton
                anchors.top: threadsMenu.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 10
                width: parent.width
                text: "asign graph to thread"
                onClicked:{
                    var id = nodesGraphContainer.getGraphIdByModelIndex(graphtoRenameMenu.currentIndex)
                    threadManager.asignNodesGraphToThread(id,threadsMenu.currentIndex);
                }
            }
        }
    }
}
