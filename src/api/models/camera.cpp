/**
 * @file
 * @brief Camera model implementation.
 */

#include "api/models/camera.h"

#include <qlogging.h>
#include <QString>
#include <QUrl>
// #include <QCameraDevice>
#include <QtGlobal>

// FIX: Webcam not showing in window.

namespace api {

// TODO(rakin): Allow front and back cameras.
Camera::Camera(const QString& qmlPath) {
    // Load QML file
    setSource(QUrl::fromLocalFile(qmlPath));

    m_captureSession.setCamera(&m_camera);
    m_captureSession.setImageCapture(&m_imageCapture);
    Q_ASSERT(m_captureSession.camera() != nullptr);
    Q_ASSERT(m_captureSession.imageCapture() != nullptr);

    // Setup camera preview
    m_captureSession.setVideoOutput(&m_videoWidget);
    Q_ASSERT(m_captureSession.videoOutput() != nullptr);
    // m_videoWidget.show();
    qInfo("Showing video widget.");

    // Start camera
    m_camera.start();
    qInfo("Camera started.");
}

}  // namespace api
