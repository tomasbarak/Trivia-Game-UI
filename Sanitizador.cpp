#include "functions.h"
using namespace estadisticasUsuario;

std::string estadisticasUsuario::sanitization(std::string to_sanitize){
    std::string saneString;
    for(int i = 0; i < to_sanitize.size(); i++){
        if(isalpha(to_sanitize[i])){
            saneString = saneString + to_sanitize[i];
        }else if(to_sanitize[i]==' '){
            saneString = saneString + '_';
        }
    }
    return saneString;
}
