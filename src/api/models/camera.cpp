/**
 * @file
 * @brief Camera model implementation.
 */

#include "api/models/camera.h"
#include "ui_camera.h"

#include <QCamera>
#include <QCameraDevice>

namespace api {

Camera::Camera() :
    m_ui { new Ui::Camera },
    // TODO: Allow front and back cameras.
    m_camera { new QCamera { QCameraDevice::FrontFace } } {
    m_ui->setupUi(this);
    m_camera->start();
}

}  // namespace api
