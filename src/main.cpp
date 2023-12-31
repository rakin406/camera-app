/**
 * @file
 * @brief Entrypoint for the application.
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUrl>

int main(int argc, char* argv[]) {
    QGuiApplication app { argc, argv };

    QQmlApplicationEngine engine {};
    // engine.addImportPath(QStringLiteral("qrc:/"));
    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));

    return app.exec();
}
