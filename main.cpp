#include <SFML/Graphics.hpp>
#include <iostream>
#include "functions.h"

sf::RenderWindow window(sf::VideoMode(1000, 500), "Trivia game");

void welcomePollEvents();
void clearScreen()
{
    window.clear();
}

int main()
{
    createWelcomeScreen();
    return 0;
}

//-------------------WelcomeScreen--------------

void createWelcomeScreen()
{

    //Declaracion de objetos y variables

    //Comunes
    std::string user;
    std::string environment = "welcome";
    sf::Font font;
    sf::Image image;
    int i = 255;

    //WelcomeScreen
    sf::Clock myClock;
    sf::Clock myClock2;
    bool showCursor = false;
    sf::String playerInput;
    sf::Text playerText;
    sf::Text inputCursor;
    sf::RectangleShape rectangle(sf::Vector2f(1000.f, 500.f));
    sf::RectangleShape intputBackground(sf::Vector2f(1000.f, 500.f));
    sf::Sprite sprite;

    //Propiedades del input del usuario en la pantalla Welcome
    playerText.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = playerText.getLocalBounds();
    playerText.setOrigin(textRect.left + textRect.width/2.0f,
                         textRect.top  + textRect.height/2.0f);
    playerText.setFillColor(sf::Color{ 150, 150, 150 });

    //Propiedades del indicador para ingresar el usuario
    inputCursor.setFillColor(sf::Color::Black);
    inputCursor.setString("Nombre de usuario:   ");
    inputCursor.setPosition(360.f, 201.f);

    //Color de fondo para todas las pantallas
    rectangle.setFillColor(sf::Color{ 255, 255, 255 });

    //Propiedades del logo en la pantalla Welcome
    image.loadFromFile("SoftVisionLogoNoBGSmoke.png");
    sf::Texture texture;
    texture.loadFromImage(image);  //Load Texture from image
    sprite.setScale(0.125f, 0.125f);
    sprite.setPosition(436, 0);
    sprite.setTexture(texture);

    //Loading screen
    sf::CircleShape loadingCircle(15.f, 100);
    sf::Text labelBienvenido;

    //Propiedades del logo de carga
    loadingCircle.setOrigin(7.5f, 7.5f);
    loadingCircle.setPosition(500, 250);

    //Propiedades label bienvenido
    labelBienvenido.setFillColor(sf::Color{150, 150, 150});

    labelBienvenido.setCharacterSize(24);




    //Establecimiento de fuente Montserrat
    font.loadFromFile("Montserrat-Regular.ttf");
    playerText.setFont(font);
    inputCursor.setFont(font);
    labelBienvenido.setFont(font);

    //Loop ejecutado mientras que la pantalla este abierta
    while (window.isOpen())
    {

        //Cada 350 milisegundos
        if(myClock.getElapsedTime() >= sf::milliseconds(350))
        {
            //Vuelvo el reloj a 0
            myClock.restart();

            showCursor = !showCursor;

            //Si la variable showCursor es verdadera, muestro el cursor
            if(showCursor)
            {
                //Si el usuario no ha ingresado ningun caracter, el cursor sera = '|'
                if(user.size() < 1)
                {
                    playerText.setString(user+"|");
                }
                //Si el usuario ya ha ingresado por lo menos 1 caracter, el cursor va a ser = '_'
                else
                {
                    playerText.setString(user+"_");
                }
            }
            else
                //Si la variable showCursor es falsa, no muestro el cursor
            {
                playerText.setString(user);
            }
        }

        //Actualizo la posicion de los caracteres ingresados en cada fotograma
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

        //Disparador de eventos
        while (window.pollEvent(event))
        {

            //Si el evento es = boton de cerrar ventana
            if (event.type == sf::Event::Closed)

                //Cierro la ventana
                window.close();

            //Si el evento = tecla presionada
            if (event.type == sf::Event::TextEntered)
            {
                //Si la tecla presionada = Tecla de borrar
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
                {
                    //Si el usuario ingreso algun caracter
                    if(user.size() > 0)
                    {
                        //Borro el ultimo caracter de la string que contiene el total de los caracteres ingresados
                        user.pop_back();
                        playerText.setString(user);
                    }
                }
                else
                {
                    //Si la tecla presionada = Tecla Enter
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        //Si el usuario escribio algo
                        if(user.size() > 0)
                        {
                            //Defino el environment como "home", esto hara que se cambie de pantalla
                            environment = "loading";
                            window.clear();
                        }
                    }
                    else
                        //Si la tecla presionada no era la tecla de espacio ni la de enter
                    {
                        //Si el texto ingresado hasta ahora es menor a 17
                        if(user.size() < 17)
                        {
                            //Agrego el caracter ingresado a mi string
                            user += event.text.unicode;
                            playerText.setString(user);
                        }
                    }
                }


            }
        }

        //Color de fondo
        window.draw(rectangle);

        bool visible = false;

        if(myClock2.getElapsedTime() > sf::milliseconds(5))
        {
            myClock2.restart();

            i --;

            loadingCircle.setFillColor(sf::Color( 13, 152, 218, i ));
        }

        //Renderizado de Welcome screen
        if(environment == "welcome")
        {
            //Logo
            window.draw(sprite);
            //Texto ingresado
            window.draw(playerText);
            //Indicador de ingresar texto
            window.draw(inputCursor);
        }

        //Renderizado de Home screen
        else if(environment == "loading")
        {
            bool visible = true;
            labelBienvenido.setString("Hola " + user + ", bienvenido al juego de trivia!");

            sf::FloatRect welcomeBounds = labelBienvenido.getLocalBounds();

            labelBienvenido.setOrigin(welcomeBounds.left + welcomeBounds.width/2.0f, welcomeBounds.top + welcomeBounds.height/2.0f);

            labelBienvenido.setPosition(sf::Vector2f(1000/2.0f,500/4.0f));

            window.draw(labelBienvenido);
            window.draw(loadingCircle);


        }
        window.display();
        window.clear();

    }
}
