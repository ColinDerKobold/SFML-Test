#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MyRogueGame",
        sf::Style::Close | sf::Style::Titlebar );

    sf::Event evnt;
    while (window.pollEvent(evnt)) {
        if (evnt.type == evnt.Closed) {
            window.close();
        }
    }

    return 0;
}