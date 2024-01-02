import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
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
        imageCapture : ImageCapture {
            id: imageCapture
        }
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

            signal startedRecording
            signal stoppedRecording

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

                onClicked: startedRecording
            }

            RoundButton {
                id: captureButton
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
                Layout.bottomMargin: 40

                Image {
                    anchors.fill: parent
                    source: "qrc:/images/capture-icon.png"
                    fillMode: Image.PreserveAspectFit
                }

                onClicked: {
                    imageCapture.capture()
                    folderDialog.open()
                }

                FolderDialog {
                    id: folderDialog
                    currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                    onAccepted: imageCapture.saveToFile(selectedFolder)
                }
            }
        }
    }
}
