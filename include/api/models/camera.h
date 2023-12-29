/**
 * @file
 * @brief Camera model.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <QAbstractItemModel>
#include <QCamera>
#include <QImageCapture>
#include <QMediaRecorder>
#include <QScopedPointer>

namespace api::models {

class Camera : public QAbstractItemModel {
    Q_OBJECT

public:
    explicit Camera(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
                  int role = Qt::DisplayRole) const override;

private slots:
    // void record();
    // void pause();
    // void stop();
    // void takeImage();

private:
    api::models::Camera* m_model;

    QScopedPointer<QCamera> m_camera {};
    QScopedPointer<QImageCapture> m_imageCapture {};
    QScopedPointer<QMediaRecorder> m_mediaRecorder {};

    QString m_videoContainerFormat {};
    bool m_isCapturingImage { false };
    bool m_isAppExiting { false };
};

}  // namespace api::models

#endif
