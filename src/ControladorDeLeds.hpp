#include "enums/EstadoBuildEnum.hpp"

class ControladorDeLeds {
    public: 
        ControladorDeLeds();
        void prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild);
    private: 
        void apagarTodosLosLeds();
};