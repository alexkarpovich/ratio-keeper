import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

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

        delegate: Item {
            property var view: GridView.view
            property var isCurrent: GridView.isCurrentItem

            height: view.cellHeight
            width: view.cellWidth

            Rectangle {
                id: rect
                anchors.margins: 5
                anchors.fill: parent
                color: '#169632'
                border {
                    color: "black"
                    width: 1
                }

                Text {
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    text: model.modelData
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index

                        var selIndex = selected.indexOf(model.index);

                        if (selIndex === -1) {
                            selected.push(model.index);
                            view.currentItem.state = 'selected'
                        } else {
                            selected.splice(selIndex, 1);
                            view.currentItem.state = ''
                        }

                        console.log(model.index, model.modelData, selected);
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

    Button {
        id: continueBtn
        anchors {
            bottom: parent.bottom
            bottomMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
        text: 'Продолжить'

        onClicked: {
            var categoryNames = [];

            for (var i = 0; i < selected.length; i++) {
                categoryNames.push(categoryModel[selected[i]]);
            }

            appCore.configureInstance(categoryNames)
        }
    }
}
