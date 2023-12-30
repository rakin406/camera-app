import QtQuick

Window {
    id: mainWindow
    title: "Camera"

    CaptureSession {
        id: captureSession
        camera: Camera {
            id: camera
        }
        imageCapture: ImageCapture {
            id: imageCapture
        }

        recorder: MediaRecorder {
            id: recorder
        }
        videoOutput: preview
    }
}
