#include "functions.h"
using namespace std;


vector<string> readStats(std::string userName, bool createUser){
    ifstream userLifesR;
    ifstream userScoreR;
    ofstream newuserLifes;
    ofstream newuserScore;
    ofstream newuserStack;

    //Busco el archivo que contenga las vidas del usuario ingresado
    userLifesR.open("./datos/usuario/lifes/" + userName + ".data");

    string read_lifes;
    string read_score;
    string userRead;
    vector <string> statsVector = {"null", "null", "null"};

    //Si existe, leo lo que tenga adentro
    if (userLifesR.is_open())
    {
        //Obtengo las vidas restantes del usuario
        getline(userLifesR, read_lifes, '\n');

        userLifesR.close();

        // No vamos a abrir esta caja de pandora. Por ahora.
        /*
        // Los usuarios viejos tenian sus nombres y después sus vidas. Habría que actualizar los datos si encontramos que usan ese formato.
        if (static_cast<int>(userLifesR[0]) - 48 > 9 || static_cast<int>(userLifesR[0]) - 48 < 0) {
            // La primera letra del archivo NO ES UN NUMERO, asumimos que usa el formato viejo

        }
        */

        userScoreR.open("./datos/usuario/maxscores/" + userName + ".data");
        if(userScoreR.is_open())
        {
            //Obtengo el puntaje maximo del usuario
            getline(userScoreR, read_score);
        }
        else
        {
            //Si el puntaje maximo no existe, lo defino en 0
            read_score = "0";
        }
        userScoreR.close();
        //cout << endl <<" Hola de nuevo " << userName << "! " << endl;
        statsVector[0] = read_score;
        statsVector[1] = read_lifes;
        statsVector[2] = userName;

        return statsVector;

        //return 1;
        //Si no existe, significa que es un usuario nuevo, osea que se creara un archivo que contenga el nombre y las 3 vidas del usuario
    }
    else
    {
        //cout << " Nuevo usuario detectado!" << endl;


        //cout << " Desea crear un nuevo usuario?(S/N): ";

        //cin >> crearUsuario;


        if(createUser)
        {
            //cout << endl << " Creando usuario..." << endl;
            newuserLifes.open("./datos/usuario/lifes/" + userName + ".data");
            newuserLifes << "3";
            newuserLifes.close();

            newuserScore.open("./datos/usuario/maxscores/" + userName + ".data");
            newuserScore << "0";
            newuserScore.close();


            newuserStack.open("./datos/usuario/users.data", ios::app);
            newuserStack << userName << '\n';
            newuserStack.close();
            //cout << " Usuario creado con exito, bienvenido al juego!" << endl;

            return statsVector;
            //return 1;
        }
        else
        {
            return {};
        }
    }

    return {};
}
