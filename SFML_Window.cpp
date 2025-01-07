#include <QApplication>
#include <QMessageBox>
#include <SFML/Graphics.hpp>
#include <iostream>

void handleRectangleMovement(sf::RectangleShape& rectangle) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rectangle.move(-5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rectangle.move(5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rectangle.move(0, -5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rectangle.move(0, 5);
    }
}

void ShowVersion(void) {

    // Versionen von
    // SLMF
    // Qt
    // anzeigen lassen:

     
    std::cout   << "SFML-Version: "
                << SFML_VERSION_MAJOR << "."
                << SFML_VERSION_MINOR << "."
                << SFML_VERSION_PATCH
                << std::endl;

    std::cout   << "Qt-Version: "
                << QT_VERSION_STR << std::endl;
    std::cout   << "Kompilierung mit g++ Version: " << __VERSION__ << std::endl;
    std::cout << "Dieses Programm wurde kompiliert am: " << __DATE__ << std::endl;
    std::cout << "Zur Uhrzeit: " << __TIME__ << std::endl;
    std::cout << "Datei: " << __FILE__ << std::endl;    
    std::cout << "C++-Standard: " << __cplusplus << std::endl;
    
    std::cout << "Funktion: " << __func__ << "[" << __PRETTY_FUNCTION__ << "]" << std::endl;  

    

    
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    ShowVersion();
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mein erstes SFML-Programm!");
    window.setPosition(sf::Vector2i(10, 50));
    window.setFramerateLimit(60);

    // Rechteck erstellen
    
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(350, 275);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                QMessageBox::information(nullptr, "HINWEIS", "Auf Wiedersehen");
            }
        }

        // Bewegung des Rechtecks verwalten
        handleRectangleMovement(rectangle);

        // Fensterinhalt zeichnen
        window.clear(sf::Color(125, 100, 0, 200));
        window.draw(rectangle); // Rechteck zeichnen
        window.display();
    }

    return 0;
}
