import QtQuick 2.0
import QtQuick.Controls 2.0
import "customize" as Customize

Item {
    anchors.fill: parent

    PageIndicator {
        id: indicator

        count: customize.count
        currentIndex: customize.currentIndex

        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    SwipeView {
        id: customize

        currentIndex: 0
        anchors.top: indicator.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Customize.StepI {}

        Customize.StepII {}
    }
}
