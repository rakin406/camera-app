/**
 * @file
 * @brief Camera model.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <memory>

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
    std::unique_ptr<QCamera> m_camera {};
    std::unique_ptr<QImageCapture> m_imageCapture {};
    std::unique_ptr<QVideoWidget> m_videoWidget {};

    QMediaCaptureSession m_captureSession {};
    QMediaRecorder m_mediaRecorder {};
};

}  // namespace api

#endif
