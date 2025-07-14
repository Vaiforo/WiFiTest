import QtQuick 2.0
import Sailfish.Silica 1.0
import AuroraApp 1.0

ApplicationWindow {
    initialPage: Component {
        Page {
            Column {
                anchors.centerIn: parent
                spacing: Theme.paddingLarge

                WiFiBSSID { id: wifi }

                Label {
                    id: currentLabel
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                    text: qsTr("BSSID: ") +
                          (wifi.currentBSSID.length > 0
                           ? wifi.currentBSSID
                           : qsTr("(unknown)"))

                    Connections {
                        target: wifi
                        onCurrentBSSIDChanged: currentLabel.text =
                            qsTr("BSSID: ") +
                            (wifi.currentBSSID.length > 0
                             ? wifi.currentBSSID
                             : qsTr("(unknown)"))
                    }
                }

                Button {
                    text: qsTr("Получить BSSID")
                    onClicked: wifi.fetchCurrentBSSID()
                }

                Button {
                    text: qsTr("Запомнить")
                    onClicked: wifi.saveCurrentBSSID()
                }

                Button {
                    text: qsTr("Проверить")
                    onClicked: {
                        var ok = wifi.checkSavedBSSID()
                        resultLabel.text =
                            ok ? qsTr("Совпадает")
                               : qsTr("Не совпадает")
                    }
                }

                Label {
                    id: resultLabel
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    text: ""
                }
            }
        }
    }
}
