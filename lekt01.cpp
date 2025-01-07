#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 2x Fenster erstellen
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mein erstes SFML-Programm!");
	sf::RenderWindow window2(sf::VideoMode(320, 200), "kleineres Fenster");

    // Schriftarten laden
    sf::Font font;
	sf::Font font2;

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Fehler: Schriftart konnte nicht geladen werden!" << std::endl;
        return -1;
    }

	if (!font2.loadFromFile("KOMIKAP_.ttf")) {
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

	// Create a text which uses our font
	sf::Text text1;
	text1.setFont(font);
	text1.setString("Simmer!");
	text1.setCharacterSize(20);
	text1.setFillColor(sf::Color::Blue);
	text1.setStyle(sf::Text::Regular);
	text1.setPosition(100.f, 150.f);
	
	// Create a text which uses our font
	sf::Text myFont;
	myFont.setFont(font2);
	myFont.setString("SimmerLein!");
	myFont.setCharacterSize(20);
	myFont.setFillColor(sf::Color::Blue);
	myFont.setStyle(sf::Text::Regular);
	myFont.setPosition(10.f, 15.f);




    // Hauptprogramm-Schleife
    while ((window.isOpen()) || (window2.isOpen())) {
        sf::Event event;
        while ((window.pollEvent(event) || (window2.pollEvent(event)))) {
            if (event.type == sf::Event::Closed) {
                window.close();
				window2.close();
            }
        }

        // Fensterinhalt zeichnen
        window.clear(sf::Color(125, 100, 0, 200));		
		window.draw(text);
		window.draw(text1);		
	    window.display();

		window2.clear(sf::Color::Yellow);
        window2.draw(myFont);
    	window2.display();
	
    }

    return 0;
}
