/**
 * @file
 * @brief Camera controller.
 */

#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include "api/models/camera.h"

#include <QCamera>
#include <QImageCapture>
#include <QMediaRecorder>
#include <QObject>

namespace api {

class CameraController : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Constructor for CameraController.
     *
     * @param camera Camera model class.
     */
    explicit CameraController(Camera& camera);

signals:
    // Buttons clicked
    void recordClicked();
    void pauseClicked();
    void stopClicked();
    void captureClicked();

private slots:
    // Record video
    void record();

    // Pause video recording
    void pause();

    // Stop video recording
    void stop();

    // Capture image
    void capture();

private:
    Camera* camera {};
};

}  // namespace api

#endif
