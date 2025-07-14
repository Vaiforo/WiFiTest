#include "wifitest.h"
#include "bssidreader.h"
#include <QDebug>

void WiFiBSSID::fetchCurrentBSSID()
{
    const QString mac = getCurrentBssid("wlan0");
    m_currentBSSID   = mac.isEmpty()
                       ? QStringLiteral("<not_found>")
                       : mac;
    emit currentBSSIDChanged();
}

void WiFiBSSID::saveCurrentBSSID()
{
    m_savedBSSID = m_currentBSSID;
    emit savedBSSIDChanged();
}

bool WiFiBSSID::checkSavedBSSID()
{
    return !m_currentBSSID.isEmpty() &&
           m_currentBSSID == m_savedBSSID;
}
