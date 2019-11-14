#include "enums/EstadoBuildEnum.hpp"

class ControladorDeLeds {
    public: 
        ControladorDeLeds();
        void prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild);
        void configurarPaletaColoresLed(int ledRojo, int ledAzul, int ledVerde);
    private: 
        void apagarTodosLosLeds();
};