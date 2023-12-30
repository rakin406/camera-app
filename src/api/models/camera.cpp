/**
 * @file
 * @brief Camera model implementation.
 */

#include "api/models/camera.h"

#include <qlogging.h>
#include <QCamera>
#include <QCameraDevice>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QtGlobal>

// FIX: Webcam not showing in window.

namespace api {

// TODO: Allow front and back cameras.
Camera::Camera() {
    m_captureSession.setCamera(&m_camera);
    m_captureSession.setImageCapture(&m_imageCapture);
    Q_ASSERT(m_captureSession.camera() != nullptr);
    Q_ASSERT(m_captureSession.imageCapture() != nullptr);

    // Show camera preview
    m_captureSession.setVideoOutput(&m_videoWidget);
    Q_ASSERT(m_captureSession.videoOutput() != nullptr);
    m_videoWidget.show();
    qInfo("Showing video widget.");

    m_camera.start();
    qInfo("Camera started.");
}

}  // namespace api
