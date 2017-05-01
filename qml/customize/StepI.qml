import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import AppCore 1.0

Item {
    property var currency: customizeCore.currency;

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 5

        RowLayout {
            id: currencyRow

            Label {
                text: qsTr('Валюта')
                font.pixelSize: 14
            }

            Button {
                text: currency.code

                onClicked: {
                    appCore.setState(AppCore.CURRENCY_LIST)
                }
            }
        }

        Label {
            id: usernameLbl
            font.pixelSize: 14
            text: qsTr('Имя пользователя:')
        }

        TextField {
            id: username
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Label {
            id: emailLbl
            font.pixelSize: 14
            text: qsTr('E-mail:')
        }

        TextField {
            id: email
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Label {
            id: firstNameLbl
            font.pixelSize: 14
            text: qsTr('Имя:')
        }

        TextField {
            id: firstName
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Label {
            id: lastNameLbl
            font.pixelSize: 14
            text: qsTr('Фамилия:')
        }

        TextField {
            id: lastName
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
}
