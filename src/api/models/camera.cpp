/**
 * @file
 * @brief Camera model implementation.
 */

#include "api/models/camera.h"

#include <memory>

#include <qlogging.h>
#include <QCamera>
#include <QCameraDevice>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QtGlobal>

// FIX: Webcam not showing in window.

namespace api {

// TODO: Allow front and back cameras.
Camera::Camera()
    : m_camera { new QCamera { QCameraDevice::FrontFace } }
    , m_imageCapture { new QImageCapture }
    , m_videoWidget { new QVideoWidget } {
    Q_ASSERT(m_camera != nullptr);
    Q_ASSERT(m_imageCapture != nullptr);
    Q_ASSERT(m_videoWidget != nullptr);

    m_captureSession.setCamera(m_camera.get());
    m_captureSession.setImageCapture(m_imageCapture.get());
    Q_ASSERT(m_captureSession.camera() != nullptr);
    Q_ASSERT(m_captureSession.imageCapture() != nullptr);

    // Show camera preview
    m_captureSession.setVideoOutput(m_videoWidget.get());
    Q_ASSERT(m_captureSession.videoOutput() != nullptr);
    m_videoWidget->show();
    qInfo("Showing video widget.");

    m_camera->start();
    qInfo("Camera started.");
}

}  // namespace api
