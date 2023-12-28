#include <qt6/QtCore/QUrl>
#include <qt6/QtQuickWidgets/QQuickWidget>
#include <qt6/QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QQuickWidget* view = new QQuickWidget;
    view->setSource(QUrl::fromLocalFile("myqmlfile.qml"));
    view->show();

    return app.exec();
}
