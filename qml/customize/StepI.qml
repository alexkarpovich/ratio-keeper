import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import AppCore 1.0

Item {
    property var currency: customizeCore.currency;
    property var user: customizeCore.user

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
            text: user.username
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
            text: user.email
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
            text: user.firstName
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
            text: user.lastName
        }

        Button {
            text: qsTr('Сохранить')

            onClicked: {
                user.username = username.text
                user.email = email.text
                user.firstName = firstName.text
                user.lastName = lastName.text
            }
        }
    }
}
