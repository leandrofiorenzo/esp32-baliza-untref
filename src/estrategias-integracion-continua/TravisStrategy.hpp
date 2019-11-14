#include "ServidorIntegracionContinuaStrategy.hpp"

class TravisStrategy : public ServidorIntegracionContinuaStrategy {
    public: 
        TravisStrategy(); 
        virtual ~TravisStrategy();   
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};