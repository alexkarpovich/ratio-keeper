import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import AppCore 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 320
    height: 558
    title: qsTr("Ratio.Keeper")

    property bool isLoggedIn: appCore.isLoggedIn()

    function getSource(state) {
        var sourceFile = "Start.qml"

        switch (state) {
        case AppCore.START:
            sourceFile = "Start.qml";
            break;
        case AppCore.CUSTOMIZE:
            sourceFile = "Customize.qml";
            break;
        case AppCore.DASHBOARD:
            sourceFile = "Dashboard.qml";
            break;
        case AppCore.CATEGORY_ADD:
            sourceFile = "customize/CategoryAdd.qml";
            break;
        case AppCore.CURRENCY_LIST:
            sourceFile = "customize/CurrencyList.qml";
            break;
        }

        return sourceFile;
    }

    Connections {
        target: appCore

        onStateChanged: {
            contentLoader.source = getSource(state);
            isLoggedIn = appCore.isLoggedIn()
        }
    }

    header: ToolBar {
        visible: isLoggedIn
        RowLayout {
            anchors.fill: parent

            ToolButton {
                id: menuBtn

                Image {
                    id: burgerImage
                    anchors.fill: parent
                    anchors.margins: 9
                    source: "/images/menu.svg"
                }

                onClicked: {
                    menu.open()
                }
            }

            Label {
                text: "Title"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                id: profileBtn

                Image {
                    id: profileImage
                    anchors.fill: parent
                    anchors.margins: 5
                    source: "/images/profile.svg"
                }
            }
        }
    }

    Drawer {
        id: menu
        y: header.height
        width: window.width * 0.8
        height: window.height - header.height
    }

    Loader {
        id: contentLoader
        anchors.fill: parent
        source: getSource(appCore.state)
    }

    footer: TabBar {
        id: footer
        width: parent.width
        visible: isLoggedIn

        TabButton {
            text: qsTr("Dashboard")
        }
        TabButton {
            text: qsTr("Other")
        }
        TabButton {
            text: qsTr("Statictics")
        }
    }

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}
