#include "ServidorIntegracionContinuaStrategy.hpp"

class TravisStrategy : public ServidorIntegracionContinuaStrategy {
    public: 
        TravisStrategy();      
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};