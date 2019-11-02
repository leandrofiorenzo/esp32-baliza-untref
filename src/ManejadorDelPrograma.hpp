#include "ServidorIntegracionContinuaStrategy.hpp"

class ManejadorDelPrograma {
    private:
        ServidorIntegracionContinuaStrategy *servidorIntegracionContinuaStrategy;
    public: 
        ManejadorDelPrograma();
        String obtenerEstadoUltimoBuild();
        void definirEstrategia(int ci);
};