#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Hallo, Qt!");
    label.show();

    return app.exec();
}