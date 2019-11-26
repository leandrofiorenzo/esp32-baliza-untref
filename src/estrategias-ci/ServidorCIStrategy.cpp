#include "ServidorCIStrategy.h" 

ServidorCIStrategy::ServidorCIStrategy(String _tokenAcceso, String _identificadorDelRepositorio) {
    tokenAcceso = _tokenAcceso;
    identificadorDelRepositorio = _identificadorDelRepositorio;
};

ServidorCIStrategy::~ServidorCIStrategy() {
    
};

void ServidorCIStrategy::definirTokenAcceso(String _tokenAcceso) {
    tokenAcceso = _tokenAcceso;
};

void ServidorCIStrategy::definiridentificadorDelRepositorio(String _identificadorDelRepositorio) {
    identificadorDelRepositorio = _identificadorDelRepositorio;
};