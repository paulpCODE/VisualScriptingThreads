import QtQuick 2.0
import QtQuick.Controls 2.15
import "js/NodesGraphFunctions.js" as NGFunc

Item {
    id:mainitem
    property alias currentIndex: nodechoice.currentIndex

    ComboBox {
        id: nodechoice
        width: 80
        height: 30
        anchors.top: parent.top
        anchors.left: parent.left
        model: ["V1 = V2", "V = C", "INPUT V", "PRINT V", "IF V == C", "IF V < C"]
        delegate: ItemDelegate {
               width: nodechoice.width
               contentItem: Text {
                   text: modelData
                   elide: Text.ElideRight
                   verticalAlignment: Text.AlignVCenter
                   horizontalAlignment: Text.AlignHCenter
               }
        }
        contentItem: Text {


               text: nodechoice.displayText

               verticalAlignment: Text.AlignVCenter
               horizontalAlignment: Text.AlignHCenter
               elide: Text.ElideRight
           }

    }
    Button {
        height: 30
        width: 30
        anchors.left: nodechoice.right
        anchors.rightMargin: 5
        text: "+"
        onClicked: {
            if(grapheditor.componentsMap.size === 0) {
                NGFunc.instantiateBeginNode()
            }

            NGFunc.createNode()
        }
    }

}
