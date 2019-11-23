#include <Arduino.h>
#include <HTTPClient.h>
#include "enums/EstadoBuildEnum.hpp"

#ifndef ServidorCI_H
#define ServidorCI_H

class ServidorCIStrategy {
    protected: 
        String tokenAcceso;
        String repositorioId; 
    public: 
        ServidorCIStrategy();
        virtual ~ServidorCIStrategy();
        virtual EstadoBuildEnum obtenerEstadoUltimoBuild() = 0;
        virtual void definirTokenAcceso(String _tokenAccesso) = 0;
        virtual void definirRepositorioId(String _repositorioId) = 0;
};

#endif