#include <auroraapp.h>
#include <QtQuick>
#include <QQmlEngine>
#include <qqml.h>
#include "wifitest.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.template"));
    application->setApplicationName(QStringLiteral("WiFiTest"));

    qmlRegisterType<WiFiSSID>("AuroraApp", 1, 0, "WiFiSSID");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/WiFiTest.qml")));
    view->show();

    return application->exec();
}
