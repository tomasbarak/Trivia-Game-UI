#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void createWelcomeScreen();

namespace DataObtainer
{
    struct Pregunta
    {
        std::string texto_pregunta;
        std::vector<std::string> respuestas_posibles;
        std::string respuesta_correcta;
    };

    void MostrarPregunta(Pregunta datos);

    bool LoopMurio(std::vector<Pregunta> input_directo);

    std::vector<std::string> LeerArchivo(std::string& path, std::vector<int> &archivos_utilizados);

    std::vector<Pregunta> FormatearPreguntas(std::vector<std::string> texto);
}
namespace IU
{
    std::vector <std::string> respuesta_a_pregunta(DataObtainer::Pregunta pregunta);
    int mostrarMenu();
}
namespace FuncionesConvenientes
{
    std::string obtener_slice(std::string string_original, int posicion_inicial, int posicion_final, bool inclusive);
}

std::string sanitization(std::string to_sanitize);
std::vector <std::string> readStats(std::string userName, bool createUser);

#endif // FUNCTIONS_H_INCLUDED
