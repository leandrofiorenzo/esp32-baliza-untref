#include <Arduino.h>
#include "TravisStrategy.hpp"

TravisStrategy::TravisStrategy() {

};

String TravisStrategy::obtenerEstadoUltimoBuild() {
    return "travis";
};

