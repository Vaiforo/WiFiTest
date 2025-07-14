#include "wifitest.h"

void WiFiSSID::fetchCurrentSSID() {
    QDBusInterface manager("net.connman", "/", "net.connman.Manager", QDBusConnection::systemBus());
    QDBusMessage reply = manager.call("GetServices");
    if (reply.type() == QDBusMessage::ReplyMessage && !reply.arguments().isEmpty()) {
        QDBusArgument arg = reply.arguments().at(0).value<QDBusArgument>();

        QString foundSSID;
        arg.beginArray();
        while (!arg.atEnd()) {
            QDBusObjectPath objPath;
            QVariantMap properties;
            arg.beginStructure();
            arg >> objPath >> properties;
            arg.endStructure();
            QString type  = properties.value("Type").toString();
            QString state = properties.value("State").toString();
            if (type == "wifi" && (state == "ready" || state == "online")) {
                foundSSID = properties.value("Name").toString();
                break;
            }
        }
        arg.endArray();

        if (!foundSSID.isEmpty()) {
            m_currentSSID = foundSSID;
        } else {
            m_currentSSID = QStringLiteral("<не подключено>");
        }
    } else {
        m_currentSSID = QStringLiteral("<ошибка получения SSID>");
    }

    emit currentSSIDChanged();
}

void WiFiSSID::saveCurrentSSID() {
    m_savedSSID = m_currentSSID;
    emit savedSSIDChanged();
}

bool WiFiSSID::checkSavedSSID() {
    if (m_currentSSID.isEmpty() || m_savedSSID.isEmpty())
        return false;
    return m_currentSSID == m_savedSSID;
}
