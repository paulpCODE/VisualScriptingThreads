import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import vstApp 1.0
Item {
    height: 600
    width: 300
    Rectangle {
        id:listOfVariablesHeader
        anchors.left: parent.left
        anchors.top: parent.top
        color: "#C0C0C0"
        border.color: "black"
        border.width: 1
        height: 30
        width: listOfVariables.width
        Text {
            id: headerText

            anchors.centerIn: parent
            text: "Variables"
        }
    }
    ListView{
        id: listOfVariables
        anchors.top: listOfVariablesHeader.bottom
        anchors.right: functionsArea.left
        width: parent.width - functionsArea.width
        height: functionsArea.height
        flickableDirection: Flickable.VerticalFlick
        clip: true
        model: globalVariablesContainer.qstringlistGlobalVariableModel

        delegate:  Rectangle {
            border.color: "black"
            border.width: 1
            height: 30
            width: parent.width
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
        //ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        //  ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        //   ScrollBar.vertical.interactive: true
        //   width: 200; height: 200
        ScrollBar.vertical: ScrollBar { }
        contentHeight: addItemRect.height + changeItemRect.height+ deleteItemRect.height
        Rectangle{
            id:addItemRect
            property string nameToAdd: ""
            property string valueToAdd: ""
            width: parent.width
            height: titleAddItem.height + newName.height + newValue.height + addVariableButton.height + 25
            anchors.horizontalCenter: parent.horizontalCenter

            border.color: "black"
            border.width: 1


            Text {
                id: titleAddItem
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("Add Variable")
            }


            TextField{
                id: newName
                anchors.top: titleAddItem.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                placeholderText: "new variable name"
                onEditingFinished: {
                    addItemRect.nameToAdd = newName.text
                }
            }
            TextField{
                id: newValue
                anchors.top: newName.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                placeholderText: "new variable value"
                validator: IntValidator {bottom: 0; top: 2147483647}
                onEditingFinished: {
                    addItemRect.valueToAdd = newValue.text
                }
            }
            Button{
                id: addVariableButton
                anchors.top: newValue.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width
                text: "create new variable"
                onClicked:{
                    if(addItemRect.nameToAdd!==""){
                        globalVariablesContainer.createGlobalVariable(addItemRect.nameToAdd,addItemRect.valueToAdd)
                    }
                }
            }



        }
        Rectangle{
            id:changeItemRect
            property string oldNameToChange: ""
            property string newNameToChange: ""
            property string valueToChange: ""
            width: parent.width
            height: {titleChangeItem.height + oldNameToChangeField.height + newNameToChangeField.height
                     + newValueToChangeField.height + changeVariableButton.height + 30}
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: addItemRect.bottom
            anchors.topMargin: 1
            border.color: "black"
            border.width: 1


            Text {
                id: titleChangeItem
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("Rename/change variable")
            }


            TextField{
                id: oldNameToChangeField
                anchors.top: titleChangeItem.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width - 10
                placeholderText: "Old variable to rename/change"
                onEditingFinished: {
                    changeItemRect.oldNameToChange = oldNameToChangeField.text
                }
            }
            TextField{
                id: newNameToChangeField
                anchors.top: oldNameToChangeField.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width - 10
                placeholderText: "new name"
                onEditingFinished: {
                    changeItemRect.newNameToChange = newNameToChangeField.text
                }
            }
            TextField{
                id: newValueToChangeField
                anchors.top: newNameToChangeField.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width - 10
                placeholderText: "new value"
                validator: IntValidator {bottom: 0; top: 2147483647}
                onEditingFinished: {
                    changeItemRect.valueToChange = newValueToChangeField.text
                }
            }
            Button{
                id: changeVariableButton
                anchors.top: newValueToChangeField.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width
                text: "Change/rename variable"
                onClicked:{
                    if(changeItemRect.oldNameToChange!=="" && changeItemRect.newNameToChange!=="" ){
                        globalVariablesContainer.changeGlobalVariable(changeItemRect.oldNameToChange, changeItemRect.newNameToChange,changeItemRect.valueToChange)
                    }
                }
            }
        }
        Rectangle{
            id:deleteItemRect
            property string nameToDelete: ""
            width: parent.width
            height: titleDeleteItem.height + nameToDelete.height + deleteVariableButton.height + 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: changeItemRect.bottom
            anchors.topMargin: 1
            border.color: "black"
            border.width: 1


            Text {
                id: titleDeleteItem
                anchors.top: parent.top
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                text: qsTr("Delete Variable")
            }


            TextField{
                id: nameToDelete
                anchors.top: titleDeleteItem.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                placeholderText: "Variable to delete"
                onEditingFinished: {
                    deleteItemRect.nameToDelete = nameToDelete.text
                }
            }

            Button{
                id: deleteVariableButton
                anchors.top: nameToDelete.bottom
                anchors.horizontalCenter:parent.horizontalCenter
                anchors.topMargin: 5
                width: parent.width
                text: "Delete variable"
                onClicked:{
                    if(deleteItemRect.nameToDelete!==""){
                        globalVariablesContainer.deleteGlobalVariable(deleteItemRect.nameToDelete)
                    }
                }
            }

        }
    }
}
