/**
 * @file
 * @brief Entrypoint for the application.
 */

#include <QApplication>
#include <QtWidgets>

#include "api/models/camera.h"

int main(int argc, char* argv[]) {
    using namespace api;

    QApplication app(argc, argv);

    Camera camera {};
    camera.show();

    return app.exec();
}
