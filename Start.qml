import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import AppCore 1.0

Item {
    anchors.fill: parent

    Button {
        id: startBtn
        anchors {
            left: parent.left
            right: parent.right
            verticalCenter: parent.verticalCenter
            margins: 20
        }
        text: qsTr('НАЧАТЬ')
        font.pointSize: 16
    }

    Button {
        id: customizeBtn
        anchors {
            top: startBtn.bottom
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }
        text: ('<font color="%1">' + qsTr('Настроить') + '</font>').arg(customizeBtn.down ? '#0e3352' : '#1D67A4')
        font.pointSize: 10

        background: Rectangle {
            color: "transparent"
        }

        onClicked: {
            appCore.setState(AppCore.CUSTOMIZE)
        }
    }
}
