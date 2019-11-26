#include "ServidorCIStrategy.h"

class TravisCIStrategy : public ServidorCIStrategy {
    public: 
        TravisCIStrategy(String _tokenAcceso, String _identificadorDelRepositorio); 
        virtual ~TravisCIStrategy();   
        EstadoBuildEnum obtenerEstadoUltimoBuild();
};