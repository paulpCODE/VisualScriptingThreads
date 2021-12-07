import QtQuick 2.12
import QtQuick.Controls 2.15
Item {
    id:mainitem
    property alias currentIndex: choice.currentIndex
    property int itemWidth: 80
    property int itemheight: 30

    ComboBox {
        id: choice
        width: itemWidth
        height: itemheight
        anchors.top: parent.top
        anchors.left: parent.left
        delegate: ItemDelegate {
               width: choice.width
               contentItem: Text {
                   text: modelData
                   elide: Text.ElideRight
                   verticalAlignment: Text.AlignVCenter
                   horizontalAlignment: Text.AlignHCenter
               }
           }
        contentItem: Text {
               text: choice.displayText
               verticalAlignment: Text.AlignVCenter
               horizontalAlignment: Text.AlignHCenter
               elide: Text.ElideRight
           }
        model: globalVariablesContainer.qstringlistGlobalVariableModel
    }
}
