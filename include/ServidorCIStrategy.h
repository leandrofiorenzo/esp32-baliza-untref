#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include "EstadoBuildEnum.h"

#ifndef ServidorCI_H
#define ServidorCI_H

class ServidorCIStrategy {
    protected: 
        String tokenAcceso;
        String identificadorDelRepositorio; 
    public: 
        ServidorCIStrategy(String _tokenAcceso, String _identificadorDelRepositorio);
        virtual ~ServidorCIStrategy();
        virtual EstadoBuildEnum obtenerEstadoUltimoBuild() = 0;
        void definirTokenAcceso(String _tokenAcceso);
        void definiridentificadorDelRepositorio(String _identificadorDelRepositorio);
};

#endif