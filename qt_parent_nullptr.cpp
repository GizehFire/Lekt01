#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>

int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    
    // mainWindow.setFixedSize(800,600);
    mainWindow.resize(800,600);
    mainWindow.setWindowTitle("Hauptfenster");
    mainWindow.show();

    // Dialog ohne Parent
    QMessageBox::information(nullptr, "Kein Parent", "Dieser Dialog hat keinen Parent.");

    // Dialog mit Parent
    QMessageBox::information(&mainWindow, "Mit Parent", "Dieser Dialog gehört zum Hauptfenster.");

    return app.exec();
}
