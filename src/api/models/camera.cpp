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
    , m_imageCapture { new QImageCapture } {
    Q_ASSERT(m_camera != nullptr);
    Q_ASSERT(m_imageCapture != nullptr);

    QMediaCaptureSession captureSession {};
    captureSession.setCamera(m_camera.get());
    captureSession.setImageCapture(m_imageCapture.get());
    Q_ASSERT(captureSession.camera() != nullptr);
    Q_ASSERT(captureSession.imageCapture() != nullptr);
    qInfo("QMediaCaptureSession successful.");

    // Show camera preview
    std::unique_ptr<QVideoWidget> videoWidget { new QVideoWidget };
    captureSession.setVideoOutput(videoWidget.get());
    Q_ASSERT(captureSession.videoOutput() != nullptr);
    videoWidget->show();
    qInfo("Showing video widget.");

    m_camera->start();
    qInfo("Camera started.");
}

}  // namespace api
