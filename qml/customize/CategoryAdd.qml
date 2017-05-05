import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import AppCore 1.0
import Model 1.0

Item {
    id: start
    anchors.fill: parent

    Rectangle {
        id: paneForm
        height: 200
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        TextField {
            id: categoryName
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("Введите название категории")

            background: Rectangle {
                border.color: "#333"
                border.width: 0
            }
        }

        Text {
            id: categoryLabel
            anchors.bottom: categoryName.top
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Название категории:")
        }


        Button {
            id: startBtn
            anchors.top: categoryName.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Добавить")

            onClicked: {
                customizeCore.addCategory(categoryName.text);
                appCore.setState(AppCore.CUSTOMIZE);
            }
        }
    }
}
