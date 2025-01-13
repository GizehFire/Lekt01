#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>

int main(int argc, char **argv) {
	// Eine QApplication stellt immer die Basis dar
	QApplication app(argc, argv);

	// Ein Fenster mit einem Titel erzeugen
	QWidget window;
	window.setWindowTitle("Qt4-Example");

	// Ein Label mit einem Text erzeugen
	QLabel *label = new QLabel("Hello World!");
	QLabel *label2 = new QLabel("Oha, wow");

    label->setAlignment(Qt::AlignCenter);
    label2->setAlignment(Qt::AlignLeft);

	// Eine Schaltfläche mit Tastenkürzel Alt-E erzeugen, welche die Anwendung beendet
	QPushButton *button = new QPushButton("&Exit");
	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));

	// Sowohl das Label als auch die Schaltfläche vertikal ausrichten
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
    layout->addWidget(label2);
	layout->addWidget(button);
	window.setLayout(layout);

	// Das Fenster anzeigen, die Anwendung starten und ihr Ergebnis (an das Betriebssystem) zurückliefern
	window.show();
	return app.exec();
}