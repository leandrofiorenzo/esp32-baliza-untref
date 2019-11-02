#include <Arduino.h>

#ifndef ServidorCI_H
#define ServidorCI_H

class ServidorIntegracionContinuaStrategy {
    public: 
        ServidorIntegracionContinuaStrategy();
        virtual String obtenerEstadoUltimoBuild() = 0;
};

#endif