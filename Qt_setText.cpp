#include <QWidget>
#include <QApplication>
#include <QMessageBox>

int main (int argc, char *argv[]) {
    printf("Code: ");

    QApplication app(argc, argv);
    QMessageBox myMessage;

    // myMessage.setText("Hallo");
    myMessage.setInformativeText("Ja?");
    myMessage.exec();

    
    return EXIT_SUCCESS;
}