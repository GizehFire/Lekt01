#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class TimeManager {
public:
    static void update() {
        deltaTime = clock.restart().asSeconds();
    }

    static float getDeltaTime() {
        return deltaTime;
    }

private:
    static sf::Clock clock;
    static float deltaTime;
};

// Definition der statischen Variablen
sf::Clock TimeManager::clock;
float TimeManager::deltaTime = 0.0f;

enum class side { LEFT, RIGHT, NONE };


int main()
{
    // Fenster erstellen
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Sprite-Bewegung mit Delta-Zeit");

    // Textur laden
    sf::Texture texture;
    if (!texture.loadFromFile("graphics/player.png")) {
        std::cerr << "Fehler: Textur konnte nicht geladen werden!" << std::endl;
        return -1;
    }

    side playerSide = side::LEFT;

    // Sprite erstellen und Textur zuweisen
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Startposition setzen
    sprite.setPosition(100, 100);

    // Geschwindigkeit in Pixeln pro Sekunde
    float speed = 55.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Delta-Zeit aktualisieren
        TimeManager::update();
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
            

        // ESC? Programm beenden.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        
        // Bewegung mit Pfeiltasten und Delta-Zeit
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            
            sprite.setScale(1.0f,1.0f);            
            
            sprite.move(-speed * TimeManager::getDeltaTime(), 0.0f); // Nach links
            
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.setScale(-1.0f,1.0f);
            sprite.move(speed * TimeManager::getDeltaTime(), 0.0f); // Nach rechts
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0.0f, -speed * TimeManager::getDeltaTime()); // Nach oben
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0.0f, speed * TimeManager::getDeltaTime()); // Nach unten
        }

        // Fensterinhalt zeichnen
        window.clear(sf::Color::Black);
        window.draw(sprite); // Sprite zeichnen
        window.display();
    }

    return 0;
}
