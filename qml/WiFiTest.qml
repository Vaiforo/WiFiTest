import QtQuick 2.0
import Sailfish.Silica 1.0
import AuroraApp 1.0

ApplicationWindow {
    initialPage: Component {
        Page {
            Column {
                anchors.centerIn: parent
                spacing: Theme.paddingLarge

                WiFiSSID {
                    id: wifi
                }

                Label {
                    id: currentLabel
                    text: qsTr("SSID: ") + (wifi.currentSSID.length > 0
                                            ? wifi.currentSSID
                                            : "(неизвестно)")
                    horizontalAlignment: Text.AlignHCenter
                    width: parent.width
                    wrapMode: Text.WordWrap

                    Connections {
                        target: wifi
                        onCurrentSSIDChanged: {
                            currentLabel.text = qsTr("SSID: ") + (wifi.currentSSID.length > 0
                                                                  ? wifi.currentSSID
                                                                  : "(неизвестно)")
                        }
                    }
                }

                Button {
                    text: qsTr("Узнать SSID")
                    onClicked: wifi.fetchCurrentSSID()
                }

                Button {
                    text: qsTr("Запомнить")
                    onClicked: wifi.saveCurrentSSID()
                }

                Button {
                    text: qsTr("Проверить")
                    onClicked: {
                        var match = wifi.checkSavedSSID();
                        resultLabel.text = match ? qsTr("Совпадает") : qsTr("Не совпадает");
                    }
                }

                Label {
                    id: resultLabel
                    text: ""
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    width: parent.width
                }
            }
        }
    }
}
