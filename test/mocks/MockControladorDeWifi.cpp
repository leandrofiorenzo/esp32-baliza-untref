#include "ControladorDeWifi.h"

class MockControladorDeWifi : public ControladorDeWifi {
    public:    
        MockControladorDeWifi() {};
        boolean estaConectado() {
            return true;
        }
};