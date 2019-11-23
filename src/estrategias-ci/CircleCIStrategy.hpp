#include "ServidorCIStrategy.hpp"

class CircleCIStrategy : public ServidorCIStrategy {
    public:      
        CircleCIStrategy();
        virtual ~CircleCIStrategy();
        EstadoBuildEnum obtenerEstadoUltimoBuild();
        void definirTokenAcceso(String _tokenAccesso);
        void definirRepositorioId(String _repositorioId);
};