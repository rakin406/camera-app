import QtQuick

Item {
    VideoOutput {
        id: output
        anchors.fill: parent
    }
    CaptureSession {
        videoOutput: output

        Camera {
            // You can adjust various settings in here
        }
    }
}
