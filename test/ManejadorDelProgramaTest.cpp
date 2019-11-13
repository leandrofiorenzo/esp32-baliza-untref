/*
  Dado un Esp32 conectado por WiFi a un servidor Travis y con un led verde encendido
  Cuando hago un push al repositorio y me devuelve que el build es fallido
  Entonces el Esp32 apaga el led verde y enciende el led rojo
*/
/*
  Dado un Esp32 conectado por WiFi a un servidor Travis y con un led rojo encendido
  Cuando hago un push al repositorio y me devuelve que el build es correcto
  Entonces el Esp32 apaga el led rojo y enciende el led verde
*/
/*
  Dado un Esp32 conectado por WiFi a un servidor Travis y cualquier led encendido (sea verde o rojo)
  Cuando se corta la conexion de WiFi
  Entonces el Esp32 enciende un led Naranja y apaga el led encendido (sea verde o rojo)
*/
/*
  Dado un Esp32 conectado por WiFi a un servidor Travis
  Cuando hago un push al repositorio y se encuentra validando el estado actual del build
  Entonces el Esp32 encendera un led amarillo mientras realiza el procesamiento
*/
