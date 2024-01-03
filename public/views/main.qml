import QtCore
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

                    var path = StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0].toString();

                    // Remove prefixed "file://"
                    path = path.replace(/^(file:\/{2})|(qrc:\/{2})|(http:\/{2})/,"");

                    // Unescape html codes like '%23' for '#'
                    path = decodeURIComponent(path);

                    // Get date time to use as file name
                    const dateTime = new Date().toLocaleString();
                    path = path.concat("/", dateTime, ".png");

                    // BUG: QFSFileEngine::open: No file name specified,
                            QFile::remove: Empty or null file name.
                    imageCapture.saveToFile(path)
                }
            }
        }
    }
}
