#include "ControladorDeWifi.h"

class MockControladorDeWifiConectado : public ControladorDeWifi {
    public:    
        MockControladorDeWifiConectado() {};
        boolean estaConectado() {
            return true;
        }
};