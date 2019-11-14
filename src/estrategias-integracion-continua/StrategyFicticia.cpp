#include <Arduino.h>
#include "StrategyFicticia.hpp"
#include "enums/EstadoBuildEnum.hpp"

StrategyFicticia::StrategyFicticia() {

};

StrategyFicticia::~StrategyFicticia() {

};

EstadoBuildEnum StrategyFicticia::obtenerEstadoUltimoBuild() {
    return EstadoBuildEnum::EnCurso;
};

