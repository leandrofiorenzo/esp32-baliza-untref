#include "ServidorCIStrategy.h"

class MockBuildExitoso : public ServidorCIStrategy {
    public:    
        MockBuildExitoso(String _tokenAcceso, String _identificadorDelRepositorio) : ServidorCIStrategy(_tokenAcceso, _identificadorDelRepositorio) {
            
        };
        ~MockBuildExitoso() {};
        EstadoBuildEnum obtenerEstadoUltimoBuild() {
            return EstadoBuildEnum::Exitoso;
        };
        void definirTokenAcceso(String _tokenAcceso) {};
        void definiridentificadorDelRepositorio(String _identificadorDelRepositorio) {};
};