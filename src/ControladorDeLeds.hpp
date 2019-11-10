#include "enums/EstadoBuildEnum.hpp"

class ControladorDeLeds {
    public: 
        void prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild);
        void iniciarAnalisisBuild();
};