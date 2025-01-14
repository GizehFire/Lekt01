#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

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

int main()
{
    // Create a video mode object    
    VideoMode vm(1024, 768);

    // Create and open a window for the game    
    RenderWindow window(vm, "Pong", Style::Default);

    // Create a Text object called HUD
    Text hud;

    // Create a (Stream) Text object called stringstream
    std::stringstream StreamText;    
    
    // A cool retro-style font
    Font font;

    font.loadFromFile("fonts/DS-DIGIT.ttf");
    
    // Set the font to our retro-style
    hud.setFont(font);

    // Set Position
    hud.setPosition(10,10);

    hud.setCharacterSize(15);

    StreamText << "Score:";
    
    hud.setString(StreamText.str());

    float myX = 10.0f;
    float myY = 10.0f;
    float speed = 100.0f; // Geschwindigkeit in Pixeln pro Sekunde

    while (window.isOpen())
    {
       
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Quit the game when the window is closed
                window.close();
        }
       
        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        
        // Delta-Zeit aktualisieren
        TimeManager::update();

        // Bewegung mit Delta-Zeit

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            
            myY += speed * TimeManager::getDeltaTime();
            hud.setPosition(myX, myY);
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            
            myY -= speed * TimeManager::getDeltaTime();
            hud.setPosition(myX, myY);
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            
            myX -= speed * TimeManager::getDeltaTime();
            hud.setPosition(myX, myY);
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            
            myX += speed * TimeManager::getDeltaTime();
            hud.setPosition(myX, myY);
        }

        
       
        window.clear();
        window.draw(hud);
        window.display();
    }
    return 0;
}

// -lsfml-graphics -lsfml-window -lsfml-system -lQt5Widgets -lQt5Core -fPIC
