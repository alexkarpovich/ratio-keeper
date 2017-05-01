import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    property var categoryModel: customizeCore.getCategoryList()
    property var selected: []

    Column {
        spacing: 10
        anchors.fill: parent
        anchors.margins: 10

        GridView {
            id: view
            height: parent.height * 0.9
            anchors.left: parent.left
            anchors.right: parent.right
            cellHeight: 100
            cellWidth: cellHeight
            model: categoryModel
            clip: true

            delegate: CategoryItem {}
        }

        Button {
            id: continueBtn
            anchors {
                horizontalCenter: parent.horizontalCenter
            }
            text: 'Продолжить'

            onClicked: {
                var categoryNames = [];

                for (var i = 0; i < selected.length; i++) {
                    categoryNames.push(categoryModel[selected[i]]);
                }

                customizeCore.setCategoryList(categoryNames)
                appCore.configureInstance()
            }
        }
    }

    Component.onCompleted: {
        categoryModel.push(-1)
        view.model = 0;
        view.model = categoryModel
    }
}
