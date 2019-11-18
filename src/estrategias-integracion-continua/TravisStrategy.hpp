#include "ServidorIntegracionContinuaStrategy.hpp"

class TravisStrategy : public ServidorIntegracionContinuaStrategy {
    private:
        String tokenAcceso;
        //zxiel_jS6Xaaok3zgnHGzQ

        String repositorioId; 
        //25861196 dyasico
        //26796622 esp32-baliza-untref
    public: 
        TravisStrategy(); 
        virtual ~TravisStrategy();   
        EstadoBuildEnum obtenerEstadoUltimoBuild();
        void definirTokenAcceso(String _tokenAccesso);
        void definirRepositorioId(String _repositorioId);
};