import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

    property var categoryModel: appCore.getCustomCategories()
    property var selected: []

    GridView {
        id: view

        anchors.margins: 10
        anchors.fill: parent
        cellHeight: 100
        cellWidth: cellHeight
        model: categoryModel
        clip: true

        delegate: CategoryItem {}
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

    Component.onCompleted: {
        categoryModel.push(-1)
        view.model = 0;
        view.model = categoryModel
    }
}
