import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

    property var categoryList: appCore.getCategoryList()
    property var accountList: appCore.getAccountList()    

    GridView {
        id: view

        anchors.margins: 10
        anchors.fill: parent
        cellHeight: 100
        cellWidth: cellHeight
        model: categoryList
        clip: true

        delegate: Item {
            property var view: GridView.view
            property var isCurrent: GridView.isCurrentItem

            height: view.cellHeight
            width: view.cellWidth

            Rectangle {
                id: rect
                anchors.fill: parent

                Text {
                    width: parent.width
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    horizontalAlignment: Text.AlignHCenter
                    text: model.modelData.name
                    wrapMode: Text.WordWrap
                    font.pointSize: 8
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index;
                        view.currentItem.state = 'selected';
                    }
                }
            }

            states: [
                State {
                    name: 'selected'
                    PropertyChanges {
                        target: rect
                        color: '#00ce2d'
                    }
                }
            ]
        }
    }

    Component.onCompleted: {
        console.log(JSON.stringify(accountList))
    }
}
