#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main() {
    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width, height}), "MyRogueGame",
        sf::Style::Close | sf::Style::Titlebar );

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
        //Render
        window -> clear(sf::Color(0xFF8800FF));

        //Drawing

        window->display();
    }
    delete window;
    return 0;
}






/*#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    constexpr unsigned int windowWidth = 800;
    constexpr unsigned int windowHeight = 600;

    sf::RenderWindow window(
        sf::VideoMode({windowWidth, windowHeight}),
        "Simple SFML Game", sf::Style::Close | sf::Style::Titlebar
    );

    window.setFramerateLimit(60);

    // Spieler
    sf::RectangleShape paddle({120.f, 20.f});
    paddle.setFillColor(sf::Color::Green);
    paddle.setPosition({
        windowWidth / 2.f - 60.f,
        windowHeight - 40.f
    });

    constexpr float paddleSpeed = 8.f;

    // Ball
    sf::RectangleShape ball({20.f, 20.f});
    ball.setFillColor(sf::Color::Red);
    ball.setPosition({
        static_cast<float>(std::rand() % (windowWidth - 20)),
        0.f
    });

    float ballSpeed = 5.f;
    int score = 0;

    while (window.isOpen())
    {
        // Events
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Eingaben
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
            paddle.getPosition().x > 0.f)
        {
            paddle.move({-paddleSpeed, 0.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
            paddle.getPosition().x + paddle.getSize().x < windowWidth)
        {
            paddle.move({paddleSpeed, 0.f});
        }

        // Ball bewegen
        ball.move({0.f, ballSpeed});

        // Ball gefangen?
        if (ball.getGlobalBounds().findIntersection(paddle.getGlobalBounds()))
        {
            score++;
            ballSpeed += 0.5f;

            ball.setPosition({
                static_cast<float>(std::rand() % (windowWidth - 20)),
                0.f
            });
        }

        // Ball verpasst?
        if (ball.getPosition().y > windowHeight)
        {
            score = 0;
            ballSpeed = 5.f;

            ball.setPosition({
                static_cast<float>(std::rand() % (windowWidth - 20)),
                0.f
            });
        }

        // Zeichnen
        window.clear(sf::Color::Black);
        window.draw(paddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}*/