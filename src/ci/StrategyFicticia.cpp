#include <Arduino.h>
#include "StrategyFicticia.hpp"
#include "enums/EstadoBuildEnum.hpp"

StrategyFicticia::StrategyFicticia() {

};

EstadoBuildEnum StrategyFicticia::obtenerEstadoUltimoBuild() {
    return EstadoBuildEnum::Desconocido;
};

