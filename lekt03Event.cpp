#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ereignisbeispiel");

    while (window.isOpen()) {
        sf::Event event;

        // Überprüfe die Ereigniswarteschlange
        while (window.pollEvent(event)) {
            // Was für ein Ereignis ist es?
            if (event.type == sf::Event::Closed) {
                std::cout << "Fenster schließen wurde angefordert." << std::endl;
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                std::cout << "Taste wurde gedrückt: " << event.key.code << std::endl;
            } else if (event.type == sf::Event::MouseMoved) {
                std::cout << "Maus bewegt: X=" << event.mouseMove.x 
                          << ", Y=" << event.mouseMove.y << std::endl;
            }

            
        }
    
        window.clear(sf::Color(125, 100, 0, 200));
        window.display();
    }

    return 0;
}
