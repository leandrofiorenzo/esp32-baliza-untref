#include "ServidorCIStrategy.h"

class CircleCIStrategy : public ServidorCIStrategy {
    public:      
        CircleCIStrategy(String _tokenAcceso, String _identificadorDelRepositorio);
        virtual ~CircleCIStrategy();
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};