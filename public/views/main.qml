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
            icon.source: "qrc:/images/record-icon.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40

            //style: ButtonStyle {
                //padding: 0
            //}
        }
    }
}
