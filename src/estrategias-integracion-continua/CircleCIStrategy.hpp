#include "ServidorIntegracionContinuaStrategy.hpp"

class CircleCIStrategy : public ServidorIntegracionContinuaStrategy {
    public:      
        CircleCIStrategy();
        virtual ~CircleCIStrategy();
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};