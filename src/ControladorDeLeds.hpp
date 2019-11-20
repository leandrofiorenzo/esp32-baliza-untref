#include "enums/EstadoBuildEnum.hpp"

class ControladorDeLeds {
    public: 
        ControladorDeLeds();
        void prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild);
        void configurarPaletaColoresLedEstadoBuild(uint8_t ledRojo, uint8_t ledVerde, uint8_t ledAzul);
        void configurarPaletaColoresLedEstadoConexion(int pinEncendido,int pinApagado);
        long ultimaActualizacionLedAzul = 0;
    private: 
        void apagarTodosLosLeds();
};