#include "ServidorCIStrategy.h"

class MockBuildFallido : public ServidorCIStrategy {
    public:    
        MockBuildFallido(String _tokenAcceso, String _identificadorDelRepositorio) : ServidorCIStrategy(_tokenAcceso, _identificadorDelRepositorio) {
            
        };
        ~MockBuildFallido() {};
        EstadoBuildEnum obtenerEstadoUltimoBuild() {
            return EstadoBuildEnum::Fallido;
        };
        void definirTokenAcceso(String _tokenAcceso) {};
        void definiridentificadorDelRepositorio(String _identificadorDelRepositorio) {};
};