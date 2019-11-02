#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"
#include "TravisStrategy.hpp"
#include "StrategyFicticia.hpp"

ManejadorDelPrograma::ManejadorDelPrograma() {

};

String ManejadorDelPrograma::obtenerEstadoUltimoBuild() {
    return servidorIntegracionContinuaStrategy->obtenerEstadoUltimoBuild();
};

void ManejadorDelPrograma::definirEstrategia(int ci) {
    if(ci == 1) {
        servidorIntegracionContinuaStrategy = new TravisStrategy();
    } else {
        servidorIntegracionContinuaStrategy = new StrategyFicticia();
    }
};