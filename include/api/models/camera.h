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
#include <QQuickWindow>
#include <QVideoWidget>

namespace api {

class Camera : public QQuickWindow {
    Q_OBJECT

public:
    Camera();

private:
    QCamera m_camera {};
    QMediaCaptureSession m_captureSession {};
    QImageCapture m_imageCapture {};
    QVideoWidget m_videoWidget {};
    QMediaRecorder m_mediaRecorder {};
};

}  // namespace api

#endif
