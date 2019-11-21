#include "BluetoothSerial.h"

class ControladorDeBluetooth {
    private:
        BluetoothSerial bluetoothSerial;
        const char *_nombreRed;
        const char *_contrasenaRed;
    public:
        ControladorDeBluetooth();
        String obtenerTipoDeNovedad();
        const char* obtenerNombreRed();
        const char* obtenerContrasenaRed();
};