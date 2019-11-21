#include "enums/EstadoBuildEnum.hpp"

class ControladorDeLeds {
    public: 
        ControladorDeLeds();
        void prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum estadoConexion);
        void prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild);
        void configurarPaletaColoresLedEstadoBuild(uint8_t ledRojo, uint8_t ledVerde, uint8_t ledAzul);
        void configurarPaletaColoresLedEstadoConexion(int pinEncendido,int pinApagado);
    private: 
        void apagarTodosLosLeds();
};