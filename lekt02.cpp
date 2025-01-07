#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 2x Fenster erstellen
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mein erstes SFML-Programm!");
	

    // Schriftarten laden
    
    sf::Font font;	

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Fehler: Schriftart konnte nicht geladen werden!" << std::endl;
        return -1;
    }
    
    // Text erstellen
    sf::Text text;
    text.setFont(font);
    text.setString("Hallo, Welt!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(200.f, 250.f);

    // Hauptprogramm-Schleife
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();				
            }
        }

        // Fensterinhalt zeichnen
        window.clear(sf::Color(125, 100, 0, 200));		
		window.draw(text);		
	    window.display();	
    }

    return 0;
}
