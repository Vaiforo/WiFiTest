TARGET = ru.template.WiFiTest

CONFIG += \
    auroraapp

QT += quick

PKGCONFIG += \

SOURCES += \
    src/bssidreader.cpp \
    src/main.cpp \
    src/wifitest.cpp

HEADERS += \
    src/bssidreader.h \
    src/wifitest.h

DISTFILES += \
    icons/108x108/ru.template.WiFiTest.png \
    icons/128x128/ru.template.WiFiTest.png \
    icons/172x172/ru.template.WiFiTest.png \
    icons/86x86/ru.template.WiFiTest.png \
    qml/WiFiTest.qml \
    qml/icons/WiFiTest.svg \
    rpm/ru.template.WiFiTest.changes.in \
    rpm/ru.template.WiFiTest.changes.run.in \
    rpm/ru.template.WiFiTest.spec \
    ru.template.WiFiTest.desktop

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.template.WiFiTest.ts \
    translations/ru.template.WiFiTest-ru.ts \
