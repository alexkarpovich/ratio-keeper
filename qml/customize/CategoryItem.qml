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

        Image {
            id: img
            visible: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: '/images/add.svg'
        }

        Text {
            id: txt
            width: parent.width
            anchors.centerIn: parent
            wrapMode: Text.WordWrap
            font.pointSize: 8
            horizontalAlignment: Text.AlignHCenter
            renderType: Text.NativeRendering
            text: model.modelData.name
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                view.currentIndex = model.index

                if (view.currentItem.state === 'new') {
                    appCore.setState(AppCore.CATEGORY_ADD);

                    return;
                }

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
        },
        State {
            name: 'new'
            PropertyChanges {
                target: img
                visible: true
            }
            PropertyChanges {
                target: txt
                text: ''
            }
        }
    ]

    Component.onCompleted: {
        if (+model.modelData === -1) {
            state = 'new'
        } else {
            if (selected.indexOf(model.index) === -1) {
                selected.push(model.index);
            }
            state = 'selected'
        }
    }
}
