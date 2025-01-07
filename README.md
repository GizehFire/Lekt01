# Spieleentwicklung mit SFML und Qt

Ein Lernprojekt zur Spieleentwicklung mit C++, SFML und Qt. Ziel ist es, schrittweise die Grundlagen der Spieleentwicklung zu erlernen, kleine Retro-Spiele zu entwickeln und schließlich ein BlackJack-Spiel mit einer benutzerdefinierten GUI zu erstellen.

## 🌟 Ziel
Das Projekt verfolgt folgende Lern- und Entwicklungsziele:
- **Kurzfristig:** Erstellung einfacher Retro-Spiele wie Pacman, Pong und Snake.
- **Langfristig:** Entwicklung eines funktionsfähigen BlackJack-Spiels mit moderner Benutzeroberfläche.

## 📚 Lernmethodik
Das Projekt basiert auf der Arbeit mit einem Lehrbuch und umfasst folgende Themen:
1. Einführung in die Grundlagen von SFML.
2. Erstellung grafischer Benutzeroberflächen mit Qt.
3. Kombination von SFML und Qt zur Entwicklung komplexer Spiele.

Das schrittweise Vorgehen sorgt dafür, dass praktische Erfahrungen gesammelt werden, während die theoretischen Konzepte direkt angewendet werden.

## 🔧 Technologie-Stack
- **Programmiersprache:** C++
- **Game-Engine:** [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)
- **GUI-Framework:** [Qt](https://www.qt.io/)
- **Compiler:** GCC oder Clang, kompatibel mit SFML und Qt.

## 🚀 Erste Schritte

### Voraussetzungen
- Installiere **SFML** und **Qt** auf deinem System.
- Stelle sicher, dass ein C++-Compiler (z. B. g++) korrekt eingerichtet ist.

### Installation
1. **Repository klonen:**
   ```bash
   git clone git@github.com:GizehFire/Spieleentwicklung.git
   cd Spieleentwicklung
   ```

2. **SFML-Projekt kompilieren:**
   - Für ein einfaches SFML-Spiel wie Pong:
     ```bash
     g++ pong.cpp -o pong -lsfml-graphics -lsfml-window -lsfml-system
     ./pong
     ```

3. **Qt-Projekt erstellen:**
   - Öffne das Projekt in Qt Creator oder kompiliere es manuell:
     ```bash
     qmake
     make
     ./spiel
     ```

4. **Kombiniertes Projekt (SFML und Qt):**
   - Detaillierte Anweisungen folgen, sobald das Projekt diese Phase erreicht.

## 🖥️ Lernfortschritt
- **Stufe 1:** Einführung in SFML.
  - Spiele: Pong, Snake, Pacman.
- **Stufe 2:** GUI-Erstellung mit Qt.
  - Beispiel: Spielmenüs, Einstellungen.
- **Stufe 3:** Kombination von SFML und Qt.
  - Ziel: Vollständig funktionsfähiges BlackJack-Spiel.

## 📋 Funktionen (bisher geplant)
1. **Pong:** Ein klassisches Ball- und Schlägerspiel.
2. **Snake:** Eine einfache Umsetzung des klassischen Snake-Spiels.
3. **Pacman:** Ein Labyrinth-Spiel mit einfachen Mechaniken.
4. **BlackJack:** Ein Kartenspiel mit interaktiver GUI und Animationen.

## 👥 Mitwirken
Dies ist ein persönliches Lernprojekt. Beiträge und Vorschläge sind jedoch immer willkommen:
1. Forke das Repository.
2. Erstelle einen neuen Branch:
   ```bash
   git checkout -b feature/neue-funktion
   ```
3. Sende einen Pull Request, wenn die Änderungen abgeschlossen sind.

## 📄 Lizenz
Dieses Projekt steht unter der [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.de.html). Dies bedeutet:
- Du darfst den Code nutzen, verändern und weitergeben, solange du die gleiche Lizenz beibehältst.
- Weitere Details findest du in der Datei [LICENSE](LICENSE) im Repository.

---

Viel Spaß beim Lernen und Entwickeln!
