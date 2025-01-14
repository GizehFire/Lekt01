#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML getTransform Beispiel");

    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Fehler: Schriftart konnte nicht geladen werden!" << std::endl;
        return -1;
    }

    sf::Text text("Hallo, Welt!", font, 50);
    text.setPosition(200, 150);
    text.setRotation(45);
    text.setScale(1.5, 1.5);

    // Transformationsmatrix abrufen
    sf::Transform transform = text.getTransform();

    // Transformierte Position berechnen
    sf::Vector2f originalPoint(0, 0);
    sf::Vector2f transformedPoint = transform.transformPoint(originalPoint);

    std::cout << "Transformierte Position: X=" << transformedPoint.x 
              << ", Y=" << transformedPoint.y << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
