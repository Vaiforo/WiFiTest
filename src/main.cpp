#include <auroraapp.h>
#include <QGuiApplication>
#include <QQuickView>
#include <qqml.h>

#include "wifitest.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(
        Aurora::Application::application(argc, argv));
    app->setOrganizationName(QStringLiteral("ru.template"));
    app->setApplicationName(QStringLiteral("WiFiTest"));

    qmlRegisterType<WiFiBSSID>("AuroraApp", 1, 0, "WiFiBSSID");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(
        Aurora::Application::pathTo(QStringLiteral("qml/WiFiTest.qml")));
    view->show();

    return app->exec();
}
