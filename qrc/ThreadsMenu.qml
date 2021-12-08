import QtQuick 2.12
import QtQuick.Controls 2.15

Item {
    id:mainitem
    property alias currentIndex: choice.currentIndex
    property int itemWidth: 100
    property int itemheight: 30
    width: 100
    height: 30
    ComboBox {
        id: choice
        width: itemWidth
        height: itemheight
        anchors.fill: parent
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
        model: threadManager.qstringlistThreadsModel
    }
}
