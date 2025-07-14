TARGET = ru.template.WiFiTest

CONFIG += \
    auroraapp

QT += quick dbus

PKGCONFIG += \

SOURCES += \
    src/main.cpp \
    src/wifitest.cpp

HEADERS += \
    src/wifitest.h

DISTFILES += \
    rpm/ru.template.WiFiTest.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.template.WiFiTest.ts \
    translations/ru.template.WiFiTest-ru.ts \
