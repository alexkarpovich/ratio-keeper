import QtQuick 2.0
import AppCore 1.0

Item {
    property var view: GridView.view
    property var isCurrent: GridView.isCurrentItem

    height: view.cellHeight
    width: view.cellWidth

    Rectangle {
        id: rect
        anchors.fill: parent
        anchors.margins: 2

        border {
            width: 1
            color: '#eee'
        }

        Text {
            id: txt
            anchors.centerIn: parent
            renderType: Text.NativeRendering
            text: model.modelData.code
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                customizeCore.currency = model.modelData
                appCore.setState(AppCore.CUSTOMIZE)
            }
        }
    }
}
