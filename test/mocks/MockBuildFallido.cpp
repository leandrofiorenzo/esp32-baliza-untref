#include "ServidorCIStrategy.h"

class MockBuildFallido : public ServidorCIStrategy {
    public:    
        MockBuildFallido() {};
        ~MockBuildFallido() {};
        EstadoBuildEnum obtenerEstadoUltimoBuild() {
            return EstadoBuildEnum::Fallido;
        };
        void definirTokenAcceso(String _tokenAccesso) {};
        void definirRepositorioId(String _repositorioId) {};
};