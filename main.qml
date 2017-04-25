import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import AppCore 1.0

ApplicationWindow {
    visible: true
    width: 320
    height: 480
    title: qsTr("Ratio.Keeper")

    Connections {
        target: appCore

        onStateChanged: {
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
            }

            contentLoader.source = sourceFile;
        }
    }

    Loader {
        id: contentLoader
        anchors.fill: parent
        source: "Start.qml"
    }

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}
