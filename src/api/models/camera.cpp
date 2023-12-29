/**
 * @file
 * @brief Camera model implementation.
 */

#include "api/models/camera.h"

#include <QAbstractItemModel>

namespace api::models {

Camera::Camera(QObject* parent) : QAbstractItemModel { parent } {
}

int Camera::rowCount(const QModelIndex& /*parent*/) const {
    return 2;
}

int Camera::columnCount(const QModelIndex& /*parent*/) const {
    return 3;
}

QVariant Camera::data(const QModelIndex& index, int role) const {
    return QVariant();
}

}  // namespace api::models
