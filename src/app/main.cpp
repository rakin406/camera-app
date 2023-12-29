/**
 * @file
 * @brief Entrypoint for the application.
 */

#include "api/models/camera.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    using namespace api;

    QApplication app(argc, argv);

    Camera camera {};

    return app.exec();
}
