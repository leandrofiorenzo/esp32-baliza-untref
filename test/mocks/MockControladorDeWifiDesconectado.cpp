#include "ControladorDeWifi.h"

class MockControladorDeWifiDesconectado : public ControladorDeWifi {
    public:    
        MockControladorDeWifiDesconectado() {};
        boolean estaConectado() {
            return false;
        }
};