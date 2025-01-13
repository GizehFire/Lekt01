#include <QApplication>
#include <QMessageBox>
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Muss zuerst erstellt werden
    // Fenster erstellen    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mein erstes SFML-Programm!");

    // Hauptprogramm-Schleife
    while (window.isOpen()) {
        
        sf::Event event;
        
        while (window.pollEvent(event) ) {
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {

                    QMessageBox::information(nullptr,"Hinweis: ","Leertaste gdrueckt");
                    
                }
            }            
            
            if (event.type == sf::Event::Closed) {

                window.clear(sf::Color::Red);
                window.display();
                QMessageBox::information(nullptr,"Hinweis","Auf Wiedersehen");
                window.close();
            }            
        }

        // Fensterinhalt zeichnen
        window.clear(sf::Color(125, 100, 0, 200));		
		window.display();
    }

    return 0;
}