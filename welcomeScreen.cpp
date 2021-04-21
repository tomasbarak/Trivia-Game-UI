#include <SFML/Graphics.hpp>

void createWelcomeScreen()
{
    sf::Clock myClock; // starts the clock
    bool showCursor = false;
    std::string user;
    sf::String playerInput;
    sf::Text playerText;
    sf::Font font;
    sf::Text inputCursor;
    sf::RectangleShape rectangle(sf::Vector2f(1000.f, 500.f));
    sf::RectangleShape intputBackground(sf::Vector2f(1000.f, 500.f));
    sf::Image image;
    sf::Sprite sprite;



    playerText.setFillColor(sf::Color::Black);
    inputCursor.setFillColor(sf::Color::Black);
    inputCursor.setString("Nombre de usuario:   ");
    inputCursor.setPosition(360.f, 201.f);
    font.loadFromFile("Montserrat-Regular.ttf");
    playerText.setFont(font);
    inputCursor.setFont(font);
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Trivia game");
    rectangle.setFillColor(sf::Color{ 255, 255, 255 });
    sf::FloatRect textRect = playerText.getLocalBounds();
    playerText.setOrigin(textRect.left + textRect.width/2.0f,
                         textRect.top  + textRect.height/2.0f);
    image.loadFromFile("SoftVisionLogoNoBGSmoke.png");
    sf::Texture texture;
    texture.loadFromImage(image);  //Load Texture from image
    sprite.setScale(0.125f, 0.125f);
    sprite.setPosition(436, 0);
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        playerText.setFillColor(sf::Color{ 150, 150, 150 });
        if(myClock.getElapsedTime() >= sf::milliseconds(350))
        {
            myClock.restart();
            showCursor = !showCursor;
            if(showCursor)
            {
                if(user.size() < 1)
                {
                    playerText.setString(user+"|");
                }
                else
                {
                    playerText.setString(user+"_");
                }
            }
            else
            {
                playerText.setString(user);
            }
        }
        playerText.setPosition(sf::Vector2f(1000/2.0f,500/2.0f));
        sf::FloatRect textRect2 = inputCursor.getLocalBounds();
        inputCursor.setOrigin(textRect2.width,
                              textRect2.top  + textRect2.height/2.0f);
        inputCursor.setPosition(sf::Vector2f((1000/2.0f)+25,500/2.0f));

        sf::FloatRect textRect = playerText.getLocalBounds();
        playerText.setOrigin(textRect.left,
                             textRect.top  + textRect.height/2.0f);
        playerText.setPosition(sf::Vector2f(1000/2.0f,500/2.0f));

        inputCursor.setPosition((1000/2.0), (500/2.0f));
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

        window.clear();
        window.draw(rectangle);
        window.draw(sprite);
        window.draw(playerText);
        window.draw(inputCursor);
        window.display();
    }
}
