#include "functions.h"

using namespace std;

vector<string> DataObtainer::LeerArchivo(string &path, vector<int> &archivos_utilizados)
{
    /*  RECIBE: Direccion del archivo a leer (o "random"), y un vector que utiliza como registro de los archivos que ya abrió.
        HACE: Lee las lineas del archivo insertado, y guarda los archivos ya abiertos en el vector proporcionado por el usuario.
        DEVUELVE: Un vector con las listas leidas
    */
    ifstream archivo;
    string texto_leido;

    vector<string> lineas_leidas;
    vector<string> archivos_pregunta;

    for (int i = 0; i < archivos_utilizados.size(); i++)
    {
        cout << "i: " << archivos_utilizados[i] << endl;
    }

    if (path == "random")
    {


        // Elige un archivo cualquiera.
        // Leer los archivos de pregunta del usuario
        archivo.open("datos/CustomQuestions.txt");

        if (archivo.is_open())
        {
            while (getline(archivo, texto_leido))
            {
                archivos_pregunta.push_back(texto_leido);
            }

        }

        archivo.close();

        bool archivo_nuevo = false;

        int random_number, s_t_o_p = 1;

        while (!archivo_nuevo)
        {
            if (s_t_o_p >= 1004)    // Realmente te tenes que odiar si tenes este numero de archivos personalizados
                return { "/\\/\\" };


            archivo_nuevo = true;

            random_number = rand() % (archivos_pregunta.size() + 4); // https://www.cplusplus.com/reference/cstdlib/rand/

            path = "datos/";

            if (random_number > 3)
            {
                // Pasamos a los archivos de usuario
                random_number -= 4;
                path += archivos_pregunta[random_number];

            }
            else
            {
                path.push_back(49 + random_number); // 49 --> 1 en ASCII
                path += ".data";

            }

            for (int i = 0; i < archivos_utilizados.size(); i++)
            {
                if (archivos_utilizados[i] == random_number) {
                    archivo_nuevo = false;

                }
            }

            s_t_o_p++;
        }

        archivos_utilizados.push_back(random_number);
    }

    archivo.open(path.c_str());

    if (archivo.is_open())
    {

        while (getline(archivo, texto_leido))
        {
            lineas_leidas.push_back(texto_leido);
        }
    }

    archivo.close();

    return lineas_leidas;
}

string FuncionesConvenientes::obtener_slice(string string_original, int posicion_inicial, int posicion_final, bool inclusive)
{
    string _slice;

    if (!inclusive)
    {
        for (int i = posicion_inicial; i < posicion_final; i++)
        {
            _slice += string_original[i];
        }

        return _slice;

    }
    else
    {
        for (int i = posicion_inicial; i <= posicion_final; i++)
        {
            _slice += string_original[i];
        }

        return _slice;

    }


}

bool DataObtainer::LoopMurio(vector<DataObtainer::Pregunta> input_directo)
{
    if (input_directo.size() == 0)
        return false;

    DataObtainer::Pregunta mensaje_de_muerte = { "/\\/\\", { "/\\/\\" }, "/\\/\\" };    // Pregunta que significa que el loop murió (o sea, no hay más archivos)

    DataObtainer::Pregunta primera_pregunta = input_directo[0];

    if (primera_pregunta.texto_pregunta == mensaje_de_muerte.texto_pregunta &&
        primera_pregunta.respuestas_posibles == mensaje_de_muerte.respuestas_posibles &&
        primera_pregunta.respuesta_correcta == mensaje_de_muerte.respuesta_correcta)
    {
        return true;
    }

    return false;
}

vector<DataObtainer::Pregunta> DataObtainer::FormatearPreguntas(vector<string> texto)
{
    /*  RECIBE: Un vector con lineas leidas.
        HACE: Pasa los datos sueltos del vector a la estructura Pregunta (para relacionar los datos y acceder más facil a ellos)
        DEVUELVE: Un vector con las preguntas
    */

    vector<DataObtainer::Pregunta> preguntas;

    string _pregunta;
    vector<string> _respuestas;
    string _respuesta_correcta;

    // Esta es la unica excepcion a la regla de abajo, pero la tenemos que hacer antes igual.
    if (texto[0] == "/\\/\\") {
        // No hay mas archivos
        preguntas.push_back({ "/\\/\\", { "/\\/\\" }, "/\\/\\" });

        return preguntas;

    }

    if (texto.size() % 2 != 0)
        return {};  // Como siempre son Pregunta-Respuesta, si la cantidad de lineas es impar, ALGO ESTÁ MAL.

    // Tenemos que revisar linea por linea
    for (int i = 0; i < texto.size(); i++)
    {
        int numero_linea_actual = i + 1;

        if (numero_linea_actual % 2 != 0)
        {
            // Es una pregunta
            _pregunta = texto[i];

            continue;

        }
        else
        {
            // Es una linea con respuestas

            string linea_actual = texto[i]; // Esto no lo declaramos antes porque apenas lo usamos (como te podrás imaginar, eso está por cambiar)
            vector<string> linea_cortada;
            int ultima_posicion = 0;

            // Tenemos que pasar CARACTER POR CARACTER
            for (int o = 0; o < linea_actual.size(); o++)
            {
                // Separamos las lineas por espacios
                if (linea_actual[o] == ' ')
                {
                    string _slice = FuncionesConvenientes::obtener_slice(linea_actual, ultima_posicion, o, false);  // Obtenemos la respuesta

                    _respuestas.push_back(_slice);  // Añade la respuesta al vector

                    ultima_posicion = o + 1; // Para que no apunte al espacio

                    continue;

                }
            }
            _respuesta_correcta = FuncionesConvenientes::obtener_slice(linea_actual, linea_actual.size() - 1, linea_actual.size() - 1, true); // Como la respuesta correcta no tiene un espacio atras, la obtenemos aparte

            // La linea con las respuestas es la ultima linea para cada pregunta, así que acá tenemos que crear la Pregunta y añadirla al vector

            DataObtainer::Pregunta nueva_pregunta = { _pregunta, _respuestas, _respuesta_correcta }; // Juntamos todos los datos en una pregunta

            preguntas.push_back(nueva_pregunta);

            // Reiniciamos todo (por las dudas)
            _pregunta = "";
            _respuestas.clear();
            _respuesta_correcta = "";
        }
    }
    return preguntas;
}

void DataObtainer::MostrarPregunta(Pregunta datos)
{
    cout << "Pregunta: \"" << datos.texto_pregunta << "\"" << endl;

    cout << "Respuestas Posibles: ";
    for (int i = 0; i < datos.respuestas_posibles.size() - 1; i++)
    {
        cout << datos.respuestas_posibles[i] << " ";
    }
    cout << datos.respuestas_posibles[datos.respuestas_posibles.size() - 1] << endl;

    cout << "Repuesta Correcta: " << datos.respuesta_correcta << endl << endl;
}

bool IU::respuesta_a_pregunta(DataObtainer::Pregunta pregunta)
{
    int numero_respuesta_correcta;

    if (pregunta.respuesta_correcta == "a")
        numero_respuesta_correcta = 0;

    else if (pregunta.respuesta_correcta == "b")
        numero_respuesta_correcta = 1;

    else if (pregunta.respuesta_correcta == "c")
        numero_respuesta_correcta = 2;

    else if (pregunta.respuesta_correcta == "d")
        numero_respuesta_correcta = 3;

    string respuesta;
    cout << pregunta.texto_pregunta << endl;

    cout << "[ ";
    for (int i = 0; i < pregunta.respuestas_posibles.size() - 1; i++)
    {
        cout << pregunta.respuestas_posibles[i] << " ";
    }
    cout << pregunta.respuestas_posibles[pregunta.respuestas_posibles.size() - 1] << " ]" << endl << endl;

    cout << ": ";

    //Cambié esto, porque no hacia falta un getline ya que se debe ingresar una sola letra, sin espacios

    getline(cin, respuesta);

    cout << "\n\nInsertado: " << respuesta << endl;
    cout << "Respuesta correcta(letra): " <<pregunta.respuesta_correcta << endl;
    cout << "Respuesta correcta(palabra): "<<pregunta.respuestas_posibles[numero_respuesta_correcta] << endl;

    if (respuesta == pregunta.respuesta_correcta || respuesta == pregunta.respuestas_posibles[numero_respuesta_correcta])
    {
        return true;

    }
    else
        return false;

}

vector<string> estadisticasUsuario::readStats(std::string userName){
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

        cout << endl <<" Hola de nuevo " << userName << "! " << endl;
        statsVector[0] = read_score;
        statsVector[1] = read_lifes;
        statsVector[2] = userName;

        return statsVector;

        //return 1;
        //Si no existe, significa que es un usuario nuevo, osea que se creara un archivo que contenga el nombre y las 3 vidas del usuario
    }
    else
    {
        cout << " Nuevo usuario detectado!" << endl;

        char crearUsuario;

        cout << " Desea crear un nuevo usuario?(S/N): ";

        cin >> crearUsuario;


        if(toupper(crearUsuario) == 'S')
        {
            cout << endl << " Creando usuario..." << endl;
            newuserLifes.open("./datos/usuario/lifes/" + userName + ".data");
            newuserLifes << "3";
            newuserLifes.close();

            newuserScore.open("./datos/usuario/maxscores/" + userName + ".data");
            newuserScore << "0";
            newuserScore.close();


            newuserStack.open("./datos/usuario/users.data", ios::app);
            newuserStack << userName << '\n';
            newuserStack.close();
            cout << " Usuario creado con exito, bienvenido al juego!" << endl;



            return statsVector;
            //return 1;
        }
        else
        {
            cout << endl << " Lo sentimos, sin un usuario, no puede jugar :(" << endl;
        }

        return {};
    }
}

int IU::mostrarMenu()
{
    // Lo otro era más sencillo, PERO QUE EL USUARIO PUEDA PONER DIRECTO LA RESPUESTA ES IMPORTANTE OK¿¿¿¿¿
    string s_option;
    int option;

    cout << endl << " Que desea hacer?" << endl << endl;
    cout << "   1.Ver mis estadisticas" << endl;
    cout << "   2.Restablecer usuario" << endl;
    cout << "   3.Jugar" << endl << "   : ";

    getline(cin, s_option);

    option = static_cast<int>(s_option[0]) - 48;    // Forma """"""correcta"""""" de pasar de 'char' a 'int'

    if (option > 3 || option < 1) {
        return 0;

    }

    return option;
}

void estadisticasUsuario::resetStats(std::string userName)
{
    ofstream resetUserLifes;
    ofstream resetUserScore;
    char confirmation;

    cout << endl <<"   Todas sus estadisticas(Puntaje maximo, vidas) seran restablecidas, desea continuar?(S/N)" << endl << "   : ";
    cin >> confirmation;

    if(toupper(confirmation) == 'S')
    {
        resetUserLifes.open("./datos/usuario/lifes/" + userName + ".data");
        resetUserLifes << "3";
        resetUserLifes.close();

        resetUserScore.open("./datos/usuario/maxscores/" + userName + ".data");
        resetUserScore << "0";
        resetUserScore.close();

        cout << endl <<"   Sus estadisticas han sido restablecidas" << endl;
    }
}
