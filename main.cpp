#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    int i1 = 255;
    int i2 = 285;
    int i3 = 315;


    //WelcomeScreen
    sf::Clock myClock;
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

    //Loading screen
    sf::Clock myClock2;
    sf::Clock loadTimer;
    sf::CircleShape loadingCircle1(8.f, 100);
    sf::CircleShape loadingCircle2(8.f, 100);
    sf::CircleShape loadingCircle3(8.f, 100);
    sf::Text labelBienvenido;
    sf::Text labelCarga;

    //Propiedades del logo de carga
    loadingCircle1.setOrigin(4.f, 4.f);
    loadingCircle1.setPosition(470, 250);

    loadingCircle2.setOrigin(4.f, 4.f);
    loadingCircle2.setPosition(500, 250);

    loadingCircle3.setOrigin(4.f, 4.f);
    loadingCircle3.setPosition(530, 250);

    //Propiedades label bienvenido
    labelBienvenido.setFillColor(sf::Color{150, 150, 150});
    labelBienvenido.setCharacterSize(24);

    //Propiedades label de carga
    labelCarga.setFillColor(sf::Color( 13, 152, 218, 255 ));
    labelCarga.setCharacterSize(24);
    labelCarga.setString("Espere mientras cargamos todo");

    //createUser
    sf::Text labelOops;
    sf::Text labelAcept;
    sf::Text labelUserNotExist;
    sf::Text labelSalir;
    sf::RectangleShape aceptar;
    sf::RectangleShape salir;

    //Propiedades de labelOops
    labelOops.setFillColor(sf::Color{150, 150, 150});
    labelOops.setCharacterSize(24);
    labelOops.setString("Oops!");

    //Propiedades de labelUserNotExit
    labelUserNotExist.setFillColor(sf::Color{0, 0, 0});
    labelUserNotExist.setCharacterSize(24);

    //Propiedades de los botones
    aceptar.setSize(sf::Vector2f(200, 50));
    aceptar.setFillColor(sf::Color{200, 200, 200});
    aceptar.setOutlineThickness(1.f);
    aceptar.setOutlineColor(sf::Color{13, 152, 218});

    salir.setSize(sf::Vector2f(200, 50));
    salir.setFillColor(sf::Color{200, 200, 200});
    salir.setOutlineThickness(1.f);
    salir.setOutlineColor(sf::Color::Red);

    //Propiedades de labelAcept
    labelAcept.setFillColor(sf::Color{255, 255, 255});
    labelAcept.setCharacterSize(24);
    labelAcept.setString("Aceptar");

    //Propiedades de labelSalir
    labelSalir.setFillColor(sf::Color{255, 255, 255});
    labelSalir.setCharacterSize(24);
    labelSalir.setString("Salir");

    //menu
    sf::Text menuItem1;
    sf::Text menuItem2;
    sf::Text menuItem3;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("sound.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    bool playSound1 = true;
    bool playSound2 = true;
    bool playSound3 = true;

    //Propiedades de items del menu
    menuItem1.setFillColor(sf::Color{150, 150, 150});
    menuItem2.setFillColor(sf::Color{150, 150, 150});
    menuItem3.setFillColor(sf::Color{150, 150, 150});

    menuItem1.setCharacterSize(18);
    menuItem2.setCharacterSize(18);
    menuItem3.setCharacterSize(18);

    menuItem1.setString("Jugar");
    menuItem2.setString("Ver estadisticas");
    menuItem3.setString("Restablecer usuario");

    //game
    sf::Text question;
    sf::Text answer1;
    sf::Text answer2;
    sf::Text answer3;
    sf::Text answer4;
    sf::Clock gameClock;
    int iQ = 0;

    //Propiedades de question
    question.setFillColor(sf::Color{150, 150, 150});
    question.setCharacterSize(24);

    //Propiedadesde answer1
    answer1.setFillColor(sf::Color{150, 150, 150});
    answer1.setCharacterSize(20);

    //Propiedadesde answer2
    answer2.setFillColor(sf::Color{150, 150, 150});
    answer2.setCharacterSize(20);

    //Propiedadesde answer3
    answer3.setFillColor(sf::Color{150, 150, 150});
    answer3.setCharacterSize(20);

    //Propiedadesde answer4
    answer4.setFillColor(sf::Color{150, 150, 150});
    answer4.setCharacterSize(20);

    //Establecimiento de fuente Montserrat
    font.loadFromFile("Montserrat-Regular.ttf");
    playerText.setFont(font);
    inputCursor.setFont(font);
    labelBienvenido.setFont(font);
    labelCarga.setFont(font);
    labelOops.setFont(font);
    labelUserNotExist.setFont(font);
    labelAcept.setFont(font);
    labelSalir.setFont(font);
    question.setFont(font);
    answer1.setFont(font);
    answer2.setFont(font);
    answer3.setFont(font);
    answer4.setFont(font);

    menuItem1.setFont(font);
    menuItem2.setFont(font);
    menuItem3.setFont(font);
    bool createUser = false;

    //Loop ejecutado mientras que la pantalla este abierta
    while (window.isOpen())
    {
        sf::Mouse mouse;
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
                    if(environment == "welcome")
                    {
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                        {
                            //Si el usuario escribio algo
                            if(user.size() > 0)
                            {
                                //Defino el environment como "home", esto hara que se cambie de pantalla
                                user = sanitization(user);
                                environment = "loading";
                                loadTimer.restart();
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
        }

        //Color de fondo
        window.draw(rectangle);

        bool visible = false;

        if(myClock2.getElapsedTime() > sf::milliseconds(5))
        {
            myClock2.restart();

            i1 --;
            i2 --;
            i3 --;

            loadingCircle1.setFillColor(sf::Color( 13, 152, 218, i1 ));

            loadingCircle2.setFillColor(sf::Color( 13, 152, 218, i2 ));

            loadingCircle3.setFillColor(sf::Color( 13, 152, 218, i3 ));
        }

        //Renderizado de Welcome screen
        if(environment == "welcome")
        {
            sprite.setScale(0.125f, 0.125f);
            sprite.setPosition(436, 0);
            sprite.setTexture(texture);

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

            //Posicionamiento del label de bienvenida
            sf::FloatRect welcomeBounds1 = labelBienvenido.getLocalBounds();
            labelBienvenido.setOrigin(welcomeBounds1.left + welcomeBounds1.width/2.0f, welcomeBounds1.top + welcomeBounds1.height/2.0f);
            labelBienvenido.setPosition(sf::Vector2f((1000/2.0f),500/4.0f));

            //Posicionamiento del label de carga
            sf::FloatRect loadBounds1 = labelCarga.getLocalBounds();
            labelCarga.setOrigin(loadBounds1.left + loadBounds1.width/2.0f, loadBounds1.top + loadBounds1.height/2.0f);
            labelCarga.setPosition(sf::Vector2f((1000/2.0f),500 - 500/4.0f));

            //Dibujo objetos de la pantalla Home
            window.draw(labelBienvenido);
            window.draw(loadingCircle1);
            window.draw(loadingCircle2);
            window.draw(loadingCircle3);
            window.draw(labelCarga);
            if(loadTimer.getElapsedTime() > sf::milliseconds(2500))
            {
                loadTimer.restart();
                if(readStats(user, createUser).size() < 1)
                {
                    environment = "createUser";
                }
                else
                {
                    environment = "menu";
                }
            }
        }
        else if (environment == "createUser")
        {
            //Posicionamiento labelOops
            sf::FloatRect loadBounds1 = labelOops.getLocalBounds();
            labelOops.setOrigin(loadBounds1.left + loadBounds1.width/2.0f, loadBounds1.top + loadBounds1.height/2.0f);
            labelOops.setPosition(sf::Vector2f((1000/2.0f),500/6.0f));

            //Mensaje
            labelUserNotExist.setString("El usuario '" + user + "' no existe, desea crearlo?");

            //Posicionamiento labelUserNotExist
            sf::FloatRect loadBoundsMsg = labelUserNotExist.getLocalBounds();
            labelUserNotExist.setOrigin(loadBoundsMsg.left + loadBoundsMsg.width/2.0f, loadBoundsMsg.top + loadBoundsMsg.height/2.0f);
            labelUserNotExist.setPosition(sf::Vector2f((1000/2.0f),500/2.0f));

            //Posicionamiento del boton aceptar
            sf::FloatRect loadBounds2 = aceptar.getLocalBounds();
            aceptar.setOrigin(loadBounds2.width, loadBounds2.top + loadBounds2.height/2.0f);
            aceptar.setPosition(sf::Vector2f((1000/2.0f)-50,500-500/6.0f));

            //Posicionamiento del label de boton aceptar
            sf::FloatRect loadBounds3 = labelAcept.getLocalBounds();
            labelAcept.setOrigin(loadBounds3.width, loadBounds3.top + loadBounds3.height/2.0f);
            labelAcept.setPosition((aceptar.getPosition().x-loadBounds3.width/2), aceptar.getPosition().y);

            //Button mouse hover
            if(mouse.getPosition(window).x > aceptar.getPosition().x - (loadBounds2.width) && mouse.getPosition(window).x < aceptar.getPosition().x &&
                    mouse.getPosition(window).y > aceptar.getPosition().y - (loadBounds2.height/2) && mouse.getPosition(window).y < aceptar.getPosition().y + (loadBounds2.height/2))
            {

                aceptar.setFillColor(sf::Color{13, 152, 218});
                labelAcept.setFillColor(sf::Color::White);

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {

                    createUser = true;

                    readStats(user, createUser);

                    environment = "loading";
                }

            }
            else
            {

                aceptar.setFillColor(sf::Color{255, 255, 255});
                labelAcept.setFillColor(sf::Color{50, 50, 50});

            }

            //Posicionamiento del boton salir
            sf::FloatRect loadBounds4 = salir.getLocalBounds();
            salir.setOrigin(loadBounds4.width, loadBounds4.top + loadBounds4.height/2.0f);
            salir.setPosition(sf::Vector2f((1000/2.0f)+250,500-500/6.0f));

            //Posicionamiento del label salir
            sf::FloatRect loadBounds5 = labelSalir.getLocalBounds();
            labelSalir.setOrigin(loadBounds5.width+50, loadBounds5.top + loadBounds5.height/2.0f);
            labelSalir.setPosition((salir.getPosition().x-loadBounds5.width/2), salir.getPosition().y);

            //Button salir mouse hover
            if(mouse.getPosition(window).x > salir.getPosition().x - (loadBounds4.width) && mouse.getPosition(window).x < salir.getPosition().x &&
                    mouse.getPosition(window).y > salir.getPosition().y - (loadBounds4.height/2) && mouse.getPosition(window).y < salir.getPosition().y + (loadBounds4.height/2))
            {

                salir.setFillColor(sf::Color{255, 0, 0});
                labelSalir.setFillColor(sf::Color::White);

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {
                    window.close();
                }

            }
            else
            {

                salir.setFillColor(sf::Color{255, 255, 255});
                labelSalir.setFillColor(sf::Color{50, 50, 50});

            }

            window.draw(labelOops);
            window.draw(labelUserNotExist);
            window.draw(aceptar);
            window.draw(labelAcept);
            window.draw(salir);
            window.draw(labelSalir);
        }
        else if(environment == "menu")
        {
            sf::FloatRect welcomeBounds1 = menuItem1.getLocalBounds();
            menuItem1.setOrigin(welcomeBounds1.left + welcomeBounds1.width/2.0f, welcomeBounds1.top + welcomeBounds1.height/2.0f);
            menuItem1.setPosition(sf::Vector2f(1000/2.0f,menuItem2.getPosition().y + 50));

            sf::FloatRect welcomeBounds2 = menuItem2.getLocalBounds();
            menuItem2.setOrigin(welcomeBounds2.left + welcomeBounds2.width/2.0f, welcomeBounds2.top + welcomeBounds2.height/2.0f);
            menuItem2.setPosition(sf::Vector2f(1000/2.0f, 500/2));

            sf::FloatRect welcomeBounds3 = menuItem3.getLocalBounds();
            menuItem3.setOrigin(welcomeBounds3.left + welcomeBounds3.width/2.0f, welcomeBounds3.top + welcomeBounds3.height/2.0f);
            menuItem3.setPosition(sf::Vector2f(1000/2.0f, menuItem2.getPosition().y - 50));

            //Item 1 hover
            if(mouse.getPosition(window).x > menuItem1.getPosition().x - (welcomeBounds1.width/2) && mouse.getPosition(window).x < menuItem1.getPosition().x + welcomeBounds1.width/2 &&
                    mouse.getPosition(window).y > menuItem1.getPosition().y - (welcomeBounds1.height/2) && mouse.getPosition(window).y < menuItem1.getPosition().y + (welcomeBounds1.height/2))
            {
                if(playSound1)
                {
                    sound.setPlayingOffset(sf::milliseconds(0));
                    //sound.play();
                }
                playSound1 = false;

                menuItem1.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {
                    environment = "game";
                }

            }
            else
            {
                playSound1 = true;
                menuItem1.setFillColor(sf::Color{150, 150, 150});

            }

            //Item 2 hover
            if(mouse.getPosition(window).x > menuItem2.getPosition().x - (welcomeBounds2.width/2) && mouse.getPosition(window).x < menuItem2.getPosition().x + welcomeBounds2.width/2 &&
                    mouse.getPosition(window).y > menuItem2.getPosition().y - (welcomeBounds2.height/2) && mouse.getPosition(window).y < menuItem2.getPosition().y + (welcomeBounds2.height/2))
            {
                if(playSound2)
                {
                    sound.setPlayingOffset(sf::milliseconds(0));
                    //sound.play();
                }
                playSound2 = false;

                menuItem2.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {
                    environment = "viewStats";
                }

            }
            else
            {
                playSound2 = true;
                menuItem2.setFillColor(sf::Color{150, 150, 150});

            }

            //Item 3 hover

            if(mouse.getPosition(window).x > menuItem3.getPosition().x - (welcomeBounds3.width/2) && mouse.getPosition(window).x < menuItem3.getPosition().x + welcomeBounds3.width/2 &&
                    mouse.getPosition(window).y > menuItem3.getPosition().y - (welcomeBounds3.height/2) && mouse.getPosition(window).y < menuItem3.getPosition().y + (welcomeBounds3.height/2))
            {
                if(playSound3)
                {
                    sound.setPlayingOffset(sf::milliseconds(0));
                    //sound.play();
                }
                playSound3 = false;

                menuItem3.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {
                    environment = "resetUser";
                }

            }
            else
            {
                playSound3 = true;
                menuItem3.setFillColor(sf::Color{150, 150, 150});

            }

            window.draw(menuItem1);
            window.draw(menuItem2);
            window.draw(menuItem3);
        }
        else if(environment == "game")
        {
            std::string path = "random";
            std::vector<int> archivos_utilizados;
            path = "random";
            std::vector<DataObtainer::Pregunta> preguntas = DataObtainer::FormatearPreguntas(DataObtainer::LeerArchivo(path, archivos_utilizados));
            bool stop_program = false;

            if (DataObtainer::LoopMurio(preguntas))
            {
                std::cout << "No hay mas archivos de pregunta." << std::endl;
                stop_program = true;
                continue;

            }

            std::vector <std::string> respuestas_preg;

            if(iQ < preguntas.size())
            {
                if(gameClock.getElapsedTime() > sf::milliseconds(10000))
                {
                    respuestas_preg = IU::respuesta_a_pregunta(preguntas[iQ]);
                    gameClock.restart();
                    question.setString(respuestas_preg[0]);
                    answer1.setString(respuestas_preg[2]);
                    answer2.setString(respuestas_preg[3]);
                    answer3.setString(respuestas_preg[4]);
                    answer4.setString(respuestas_preg[5]);
                    iQ++;
                }
            }

            //Posicionamiento label pregunta
            sf::FloatRect questionBounds = question.getLocalBounds();
            question.setOrigin(questionBounds.left + questionBounds.width/2.0f, questionBounds.top + questionBounds.height/2.0f);
            question.setPosition(sf::Vector2f((1000/2.0f),500/3.0f));

            //Posicionamiento label respuesta 2 (centro)
            sf::FloatRect answerBounds2 = answer2.getLocalBounds();
            answer2.setOrigin(answerBounds2.left + answerBounds2.width/2.0f, answerBounds2.top + answerBounds2.height/2.0f);
            answer2.setPosition(sf::Vector2f((1000/2.0f) - 100,500 - 500/3.0f));

            if(mouse.getPosition(window).x > answer2.getPosition().x - (answerBounds2.width/2) && mouse.getPosition(window).x < answer2.getPosition().x + answerBounds2.width/2 &&
                    mouse.getPosition(window).y > answer2.getPosition().y - (answerBounds2.height/2) && mouse.getPosition(window).y < answer2.getPosition().y + (answerBounds2.height/2))
            {
                answer2.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {

                }

            }
            else
            {
                answer2.setFillColor(sf::Color{150, 150, 150});
            }

            //Posicionamiento label respuesta 1
            sf::FloatRect answerBounds1 = answer1.getLocalBounds();
            answer1.setOrigin(answerBounds1.width, answerBounds1.top + answerBounds1.height/2.0f);
            answer1.setPosition(sf::Vector2f((answer2.getPosition().x) - 100,500 - 500/3.0f));

            if(mouse.getPosition(window).x > answer1.getPosition().x - (answerBounds1.width) && mouse.getPosition(window).x < answer1.getPosition().x &&
                    mouse.getPosition(window).y > answer1.getPosition().y - (answerBounds1.height/2) && mouse.getPosition(window).y < answer1.getPosition().y + (answerBounds1.height/2))
            {
                answer1.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {

                }

            }
            else
            {
                answer1.setFillColor(sf::Color{150, 150, 150});
            }

            //Posicionamiento label respuesta 3
            sf::FloatRect answerBounds3 = answer3.getLocalBounds();
            answer3.setOrigin(answerBounds3.left + answerBounds3.width/2.0f, answerBounds3.top + answerBounds3.height/2.0f);
            answer3.setPosition(sf::Vector2f((1000/2.0f) + 100,500 - 500/3.0f));

            if(mouse.getPosition(window).x > answer3.getPosition().x - (answerBounds3.width/2) && mouse.getPosition(window).x < answer3.getPosition().x + answerBounds3.width/2 &&
                    mouse.getPosition(window).y > answer3.getPosition().y - (answerBounds3.height/2) && mouse.getPosition(window).y < answer3.getPosition().y + (answerBounds3.height/2))
            {
                answer3.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {

                }

            }
            else
            {
                answer3.setFillColor(sf::Color{150, 150, 150});
            }

            //Posicionamiento label respuesta 4
            sf::FloatRect answerBounds4 = answer4.getLocalBounds();
            answer4.setOrigin(answerBounds4.left, answerBounds4.top + answerBounds4.height/2.0f);
            answer4.setPosition(sf::Vector2f(((answer3.getPosition().x) + 100),500 - 500/3.0f));

            if(mouse.getPosition(window).x > answer4.getPosition().x  && mouse.getPosition(window).x < answer4.getPosition().x + answerBounds4.width &&
                    mouse.getPosition(window).y > answer4.getPosition().y - (answerBounds4.height/2) && mouse.getPosition(window).y < answer4.getPosition().y + (answerBounds4.height/2))
            {
                answer4.setFillColor(sf::Color{13, 152, 218});

                if(mouse.isButtonPressed(sf::Mouse::Left))
                {

                }

            }
            else
            {
                answer4.setFillColor(sf::Color{150, 150, 150});
            }

            sf::FloatRect answerImageBounds = sprite.getLocalBounds();
            sprite.setOrigin(answerImageBounds.left + answerImageBounds.width/2.0f, answerImageBounds.top + answerImageBounds.height/2.0f);
            sprite.setScale(0.075f, 0.075f);
            sprite.setPosition(1000/2, 500 - 500/3);
            sprite.setTexture(texture);



            //question.setString();

            window.draw(question);
            window.draw(sprite);
            window.draw(answer1);
            window.draw(answer2);
            window.draw(answer3);
            window.draw(answer4);
        }
        window.display();
        window.clear();

    }
}
