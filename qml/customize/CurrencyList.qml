import QtQuick 2.0

Item {
    anchors.fill: parent
    property var currencyList: customizeCore.getCurrencyList()

    GridView {
        id: view

        anchors.fill: parent
        cellHeight: 50
        cellWidth: cellHeight
        model: currencyList
        clip: true

        delegate: CurrencyItem {}
    }
}
