/**
 * @file
 * @brief Entrypoint for the application.
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    QGuiApplication app { argc, argv };
    QQmlApplicationEngine engine { "views/camera.qml" };
    return app.exec();
}
