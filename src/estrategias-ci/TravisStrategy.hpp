#include "ServidorCIStrategy.hpp"

class TravisStrategy : public ServidorCIStrategy {
    public: 
        TravisStrategy(); 
        virtual ~TravisStrategy();   
        EstadoBuildEnum obtenerEstadoUltimoBuild();
        void definirTokenAcceso(String _tokenAccesso);
        void definirRepositorioId(String _repositorioId);
};