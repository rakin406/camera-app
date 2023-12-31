import QtQuick
import QtQuick.Controls
// import QtQuick.Controls.Styles
import QtMultimedia

ApplicationWindow {
    id: root
    visible: true
    title: "Camera"

    width: 1280
    height: 720
    minimumHeight: 100
    minimumWidth: 100

    MediaDevices {
        id: mediaDevices
    }

    SplitView {
        id: splitView
        anchors.fill: parent

        CaptureSession {
            camera: Camera {
                id: camera

                cameraDevice: mediaDevices.defaultVideoInput
            }
            videoOutput: videoOutput
        }

        VideoOutput {
            id: videoOutput
            anchors.fill: parent

            RoundButton {
                // FIX: Cannot assign to non-existent property "iconSource"
                iconSource: ":/res/recordIcon.png"
                anchors.centerIn: parent

                /*
                style: ButtonStyle {
                    padding: 0
                }
                */
            }
        }
    }
}
