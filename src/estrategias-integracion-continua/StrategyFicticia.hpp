#include "ServidorIntegracionContinuaStrategy.hpp"

class StrategyFicticia : public ServidorIntegracionContinuaStrategy {
    public:      
        StrategyFicticia();
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};