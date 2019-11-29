#include "ServidorCIStrategy.h"

class MockBuildEnCurso : public ServidorCIStrategy {
    public:    
        MockBuildEnCurso(String _tokenAcceso, String _identificadorDelRepositorio) : ServidorCIStrategy(_tokenAcceso, _identificadorDelRepositorio) {
            
        };
        ~MockBuildEnCurso() {};
        EstadoBuildEnum obtenerEstadoUltimoBuild() {
            return EstadoBuildEnum::EnCurso;
        };
        void definirTokenAcceso(String _tokenAcceso) {};
        void definiridentificadorDelRepositorio(String _identificadorDelRepositorio) {};
};