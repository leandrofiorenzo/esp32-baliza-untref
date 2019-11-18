#include "enums/EstadoBuildEnum.hpp"

class ControladorDeLeds {
    public: 
        ControladorDeLeds();
        void prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild);
        void configurarPaletaColoresLed(uint8_t ledRojo, uint8_t ledVerde, uint8_t ledAzul);
        long ultimaActualizacionLedAzul = 0;
    private: 
        void apagarTodosLosLeds();
};