/**
 * @file
 * @brief Entrypoint for the application.
 */

#include "api/models/camera.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[]) {
    using namespace api;

    QApplication app(argc, argv);

    Camera camera {};
    camera.show();

    return app.exec();
}
