#include <Arduino.h>
#include "EstadoBuildEnum.h"

#ifndef ControladorDeLeds_H
#define ControladorDeLeds_H

class ControladorDeLeds {
    public: 
        ControladorDeLeds();
        void prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum estadoConexion);
        void prenderLedCorrespondienteAlEstadoBuild(EstadoBuildEnum estadoBuild);
        void configurarPaletaColoresLedEstadoBuild(uint8_t ledRojo, uint8_t ledVerde, uint8_t ledAzul);
        void configurarPaletaColoresLedEstadoConexion(int pinEncendido,int pinApagado);
    private: 
        void apagarTodosLosLeds();
};

#endif