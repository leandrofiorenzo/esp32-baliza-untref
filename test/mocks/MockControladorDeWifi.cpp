#include "ControladorDeWifi.h"

class MockControladorDeWifi : public ControladorDeWifi {
    public:    
        MockControladorDeWifi() {};
        boolean estaConectado() {
            Serial.println("ENTRE POR ACA mock");
            return true;
        }
};