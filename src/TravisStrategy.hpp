#include "ServidorIntegracionContinuaStrategy.hpp"

class TravisStrategy : public ServidorIntegracionContinuaStrategy {
    public: 
        TravisStrategy();      
        String obtenerEstadoUltimoBuild();
};