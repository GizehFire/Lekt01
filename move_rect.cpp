#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML move Beispiel");
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
            }
        }

        // Rechteck um 5 Pixel nach rechts und 3 Pixel nach unten bewegen
        rectangle.move(sf::Vector2f(5, 3));

        // Fensterinhalt zeichnen
        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
