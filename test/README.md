# Baliza de Integración Continua con un ESP32.

## Requerimientos:

## 1. Actualizar estado de la baliza  
El estado de la baliza deberá actualizarse ante cada cambio de estado del build.

### Criterios de aceptación:

## 2. Color asociado a estado  
La baliza deberá mostra luz de color de acuerdo al estado del build:  
Exitoso => Verde  
Fallido => Rojo  

### Criterios de aceptación:  

+Dado un Esp32 conectado por WiFi a un servidor Travis y con un led verde encendido
Cuando hago un push al repositorio y me devuelve que el build es fallido
Entonces el Esp32 apaga el led verde y enciende el led rojo

+Dado un Esp32 conectado por WiFi a un servidor Travis y con un led rojo encendido
Cuando hago un push al repositorio y me devuelve que el build es correcto
Entonces el Esp32 apaga el led rojo y enciende el led verde

+Dado un Esp32 conectado por WiFi a un servidor Travis y cualquier led encendido (sea verde o rojo)
Cuando se corta la conexion de WiFi
Entonces el Esp32 enciende un led Naranja y apaga el led encendido (sea verde o rojo)

+Dado un Esp32 conectado por WiFi a un servidor Travis
Cuando hago un push al repositorio y se encuentra validando el estado actual del build
Entonces el Esp32 encendera un led amarillo mientras realiza el procesamiento


## 3. Aviso de cambio de estado    
La baliza deberá destacar el cambio de estado (Exitoso a Fallido o Fallido a Exitoso) con un alarma sonora corta y/o parpadeo de la luz.

### Criterios de aceptación:

## 4. Conexión a través de WiFi    
La baliza deberá conectarse al servidor del sistema de Integración Continua mediante WiFi.

### Criterios de aceptación:

## 5. Aviso de desconexión  
La baliza deberá destacar su desconexión con un color distinto a los demás, por ejemplo, Naranja.

### Criterios de aceptación:

## 6. Configuración de WiFi     
La baliza deberá permitir configurar la red y credenciales para conectarse a WiFi.

### Criterios de aceptación:

## 7. Configuración de build      
La baliza deberá permitir configurar la url del build monitoreado y las credenciales de acceso al sistema de Integración Continua.  

### Criterios de aceptación:

## 8. Agregar Herramienta de Integración Continua    
La baliza deberá permitir agregar conectores para nuevas herramientas de Integración Continua.

### Criterios de aceptación:
