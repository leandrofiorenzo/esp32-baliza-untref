#include "ServidorIntegracionContinuaStrategy.hpp"

class StrategyFicticia : public ServidorIntegracionContinuaStrategy {
    public:      
        StrategyFicticia();
        virtual ~StrategyFicticia();
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};