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

QT_BEGIN_NAMESPACE
namespace Ui {
class Camera;
}
QT_END_NAMESPACE

namespace api {

class Camera : public QMainWindow {
    Q_OBJECT

public:
    Camera();

private:
    Ui::Camera* m_ui {};

    std::unique_ptr<QCamera> m_camera {};
    std::unique_ptr<QImageCapture> m_imageCapture {};
    std::unique_ptr<QMediaRecorder> m_mediaRecorder {};

    QString m_videoContainerFormat {};
    bool m_isCapturingImage { false };
    bool m_isAppExiting { false };
};

}  // namespace api

#endif
