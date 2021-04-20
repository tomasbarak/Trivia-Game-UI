#include <SFML/Graphics.hpp>
int main()
{
    std::string user;
    sf::String playerInput;
    sf::Text playerText;
    sf::Font font;

    sf::Text titleLabel;

    playerText.setFillColor(sf::Color::Black);
    playerText.setOrigin(100, 25);
    playerText.setPosition(475, 200);

    titleLabel.setFillColor(sf::Color::Black);
    titleLabel.setString("User:");
    titleLabel.setOrigin(100, 25);
    titleLabel.setPosition(350, 100);

    font.loadFromFile("Montserrat-Regular.ttf");

    playerText.setFont(font);
    titleLabel.setFont(font);

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Trivia game");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape rectangle(sf::Vector2f(1000.f, 500.f));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
                {
                    if(user.size() > 0)
                    {
                        user.pop_back();
                        playerText.setString(user);
                    }
                }
                else
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        if(user.size() > 0)
                        {
                            user.pop_back();
                            playerText.setString(user);
                        }
                    }
                    else
                    {
                        if(user.size() < 17)
                        {
                            user += event.text.unicode;
                            playerText.setString(user);
                        }
                    }
                }


            }
        }


        shape.setPosition(400, 150);
        window.clear();
        window.draw(rectangle);
        window.draw(titleLabel);
        window.draw(playerText);
        window.display();
    }

    return 0;
}
