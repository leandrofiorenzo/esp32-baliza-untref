#include "ServidorCIStrategy.h"

class MockBuildExitoso : public ServidorCIStrategy {
    public:    
        MockBuildExitoso() {};
        ~MockBuildExitoso() {};
        EstadoBuildEnum obtenerEstadoUltimoBuild() {
            return EstadoBuildEnum::Exitoso;
        };
        void definirTokenAcceso(String _tokenAccesso) {};
        void definirRepositorioId(String _repositorioId) {};
};