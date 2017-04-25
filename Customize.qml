import QtQuick 2.0

Item {
    width: 360
    height: 360

    property var categoryModel: appCore.getDefaultCategories()
    property var selected: []

    GridView {
        id: view

        anchors.margins: 10
        anchors.fill: parent
        cellHeight: 100
        cellWidth: cellHeight
        model: categoryModel
        clip: true

        highlight: Rectangle {
            color: "skyblue"
        }

        delegate: Item {
            property var view: GridView.view
            property var isCurrent: GridView.isCurrentItem

            height: view.cellHeight
            width: view.cellWidth

            Rectangle {
                anchors.margins: 5
                anchors.fill: parent
                color: selected.indexOf(model.index) !== -1 ? '#cccccc' : '#fff000'
                border {
                    color: "black"
                    width: 1
                }

                Text {
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    text: "%1%2".arg(model.modelData).arg(isCurrent ? " *" : "")
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index

                        if (selected.indexOf(model.index) == -1) {
                            selected.push(model.index);
                        }

                        console.log(model.index, model.modelData, selected);
                    }
                }
            }
        }
    }
}
