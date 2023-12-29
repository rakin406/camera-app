/**
 * @file
 * @brief Camera model implementation.
 */

#include "api/models/camera.h"
#include "ui_camera.h"

#include <qlogging.h>
#include <QCamera>
#include <QCameraDevice>

namespace api {

// TODO: Allow front and back cameras.
Camera::Camera()
    : m_ui { new Ui::Camera }
    , m_camera { new QCamera { QCameraDevice::FrontFace } } {
    qInfo("Camera model loaded.");

    m_ui->setupUi(this);
    if (m_ui) {
        qInfo("Camera UI loaded.");
    } else {
        qCritical("Camera UI failed to load.");
    }

    m_camera->start();
    qInfo("Camera started.");
}

}  // namespace api
