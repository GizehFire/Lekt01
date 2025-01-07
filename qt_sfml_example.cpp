#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <iostream>

// Funktion, um das Menü zu erstellen
void showMenu(sf::RenderWindow& gameWindow) {
    
    QWidget menuWindow;
    menuWindow.setWindowTitle("Spiel-Menü");

    QVBoxLayout layout;

    QPushButton startButton("Spiel starten");
    QPushButton infoButton("Info");
    QPushButton exitButton("Beenden");

    layout.addWidget(&startButton);
    layout.addWidget(&infoButton);
    layout.addWidget(&exitButton);

    QObject::connect(&startButton, &QPushButton::clicked, [&]() {
        menuWindow.close();
        std::cout << "Spiel wird gestartet..." << std::endl;
    });

    QObject::connect(&infoButton, &QPushButton::clicked, [&]() {
        QMessageBox::information(nullptr, "Info", "Dies ist ein SFML-Spiel mit Qt-Menü.");
    });

    QObject::connect(&exitButton, &QPushButton::clicked, [&]() {
        menuWindow.close();
        gameWindow.close();
    });

    menuWindow.setLayout(&layout);
    menuWindow.show();

    QApplication::exec(); // Qt-Event-Schleife
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // SFML-Fenster erstellen
    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "SFML-Spiel");
    gameWindow.setFramerateLimit(60);

    // Menü anzeigen
    showMenu(gameWindow);

    // Hauptspiel-Schleife
    while (gameWindow.isOpen()) {
        sf::Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
        }

        gameWindow.clear(sf::Color::Black);

        // Spielinhalte hier rendern

        gameWindow.display();
    }

    return 0;
}
