/**
 * @file
 * @brief Camera model.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <memory>

#include <QCamera>
#include <QImageCapture>
#include <QMainWindow>
#include <QMediaRecorder>

namespace api {

class Camera : public QMainWindow {
    Q_OBJECT

public:
    Camera();

private:
    std::unique_ptr<QCamera> m_camera {};
    std::unique_ptr<QImageCapture> m_imageCapture {};
    std::unique_ptr<QMediaRecorder> m_mediaRecorder {};

    QString m_videoContainerFormat {};
    bool m_isCapturingImage { false };
    bool m_isAppExiting { false };
};

}  // namespace api

#endif
