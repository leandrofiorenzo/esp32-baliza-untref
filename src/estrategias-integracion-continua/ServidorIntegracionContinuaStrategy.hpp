#include <Arduino.h>
#include <HTTPClient.h>
#include "enums/EstadoBuildEnum.hpp"

#ifndef ServidorCI_H
#define ServidorCI_H

class ServidorIntegracionContinuaStrategy {
    public: 
        ServidorIntegracionContinuaStrategy();
        virtual ~ServidorIntegracionContinuaStrategy();
        virtual EstadoBuildEnum obtenerEstadoUltimoBuild() = 0;
};

#endif