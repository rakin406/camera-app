/**
 * @file
 * @brief Camera model.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QImageCapture>
#include <QMainWindow>
#include <QMediaRecorder>
#include <QScopedPointer>

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

    QScopedPointer<QCamera> m_camera {};
    QScopedPointer<QImageCapture> m_imageCapture {};
    QScopedPointer<QMediaRecorder> m_mediaRecorder {};

    QString m_videoContainerFormat {};
    bool m_isCapturingImage { false };
    bool m_isAppExiting { false };
};

}  // namespace api

#endif
