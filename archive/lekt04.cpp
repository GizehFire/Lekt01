#include <QApplication>
#include <QMessageBox>
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Muss zuerst erstellt werden

    sf::RenderWindow window(sf::VideoMode(800, 600), "Fokus Ereignisse");

    bool isPaused = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::LostFocus:
                    isPaused = true;
                    std::cout << "Fenster hat den Fokus verloren." << std::endl;
                    break;

                case sf::Event::GainedFocus:
                    isPaused = false;
                    std::cout << "Fenster hat den Fokus zurückerhalten." << std::endl;
                    break;
                case sf::Event::Resized:                    
                    std::cout << "Fenstergroesse aendern?" << std::endl;
                    
                    break;

                default:
                    break;
            }
        }

        if (!isPaused) {
            // Spiel-Logik hier ausführen
        }

        

        window.clear(sf::Color::Black);
        window.display();
    }

    return app.exec();  // Event-Loop für Qt
}
