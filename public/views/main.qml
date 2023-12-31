import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
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

        RowLayout {
            id: layout
            anchors.fill: parent
            spacing: 6

            RoundButton {
                id: recordButton
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
                Layout.bottomMargin: 40

                Image {
                    anchors.fill: parent
                    source: "qrc:/images/record-icon.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
    }
}
