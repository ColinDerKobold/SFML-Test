#include <SFML/Graphics.hpp>
#include <iostream>

enum directions {stand, look, nohat, nohatlook};

int main() {
    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width, height}), "MyRogueGame",
        sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar );
    window->setFramerateLimit(60);

    sf::Texture texture;

    if (!texture.loadFromFile("Sprites/download sprite.png")) {
        std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/download sprite.png" << std::endl;
        return -1;
    }
    sf::Sprite sprite(texture);

    sf::IntRect dir[4];

    for (int i = 0; i < 4; i++) {
        dir[i] = sf::IntRect({{115+183*i, 233}, {150,180}});
    }
    sprite.setTextureRect(dir[stand]);
    sprite.setOrigin({75,90});
    sprite.setPosition({width/2.0f,height/2.0f});
    sprite.setColor(sf::Color(0x6495EDFF));

    while (window->isOpen()) {
        while (std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }else if (const auto*keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window->close();
                }
            }
        }

        sprite.rotate(sf::degrees(1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
            sprite.move({0.0f, 1.0f});
            sprite.setTextureRect(dir[stand]);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
            sprite.move({0.0f, -1.0f});
            sprite.setTextureRect(dir[nohatlook]);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            sprite.move({-1.0f, 0.0f});
            sprite.setTextureRect(dir[nohat]);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            sprite.move({1.0f, 0.0f});
            sprite.setTextureRect(dir[look]);
        }

        //Render
        window -> clear();

        //Drawing
        window->draw(sprite);

        window->display();
    }
    delete window;
    return 0;
}