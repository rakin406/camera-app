/**
 * @file
 * @brief Camera model.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QQuickWidget>
#include <QString>
#include <QVideoWidget>

namespace api {

class Camera : public QQuickWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for Camera.
     *
     * @param qmlPath File path or URL to QML.
     */
    explicit Camera(const QString& qmlPath);

private:
    QCamera m_camera {};
    QMediaCaptureSession m_captureSession {};
    QImageCapture m_imageCapture {};
    QVideoWidget m_videoWidget {};
    QMediaRecorder m_mediaRecorder {};
};

}  // namespace api

#endif
