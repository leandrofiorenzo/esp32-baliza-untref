# Baliza de Integración Continua con un ESP32.

## Para correr los test:
pio test -e native

## Para subir el programa al ESP32:
pio run --target upload -e esp32dev

## Requerimientos:

## 1. Actualizar estado de la baliza  
El estado de la baliza deberá actualizarse ante cada cambio de estado del build.

### Criterios de aceptación:

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso  
  Cuando haya un push al repositorio y el estado del build sea exitoso  
  Entonces el ESP32 debe permanecer en estado exitoso  

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado fallido  
  Cuando haya un push al repositorio y el estado del build sea fallido  
  Entonces el ESP32 debe permanecer en estado fallido  

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso  
  Cuando haya un push al repositorio y el estado del build sea fallido  
  Entonces el ESP32 debe cambiar el estado a fallido  

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado fallido  
  Cuando haya un push al repositorio y el estado del build sea exitoso  
  Entonces el ESP32 debe cambiar el estado a exitoso  

## 2. Color asociado a estado  
La baliza deberá mostra luz de color de acuerdo al estado del build:  
Exitoso => Verde  
Fallido => Rojo  

### Criterios de aceptación: 

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
  Cuando el estado del build sea exitoso  
  Entonces el ESP32 debe encender el led verde de la baliza  

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
  Cuando el estado del build sea fallido  
  Entonces el ESP32 debe encender el led rojo de la baliza 

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
  Cuando el estado del build sea validando  
  Entonces el ESP32 debe encender el led azul de la baliza  

## 3. Aviso de cambio de estado    
La baliza deberá destacar el cambio de estado (Exitoso a Fallido o Fallido a Exitoso) con un alarma sonora corta y/o parpadeo de la luz.

### Criterios de aceptación:

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua y la baliza con el led verde encendido 
  Cuando haya un push al repositorio y el estado del build sea fallido    
  Entonces el ESP32 debe apagar el led verde de la baliza y encender el rojo  

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua y la baliza con el led rojo encendido  
  Cuando haya un push al repositorio y el estado del build sea exitoso   
  Entonces el ESP32 debe apagar el led rojo de la baliza y encender el verde   

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
  Cuando haya un push al repositorio y el build se encuentre en curso  
  Entonces el ESP32 debe encender el led amarillo de la baliza mientras se procesa    

## 4. Conexión a través de WiFi    
La baliza deberá conectarse al servidor del sistema de Integración Continua mediante WiFi.

### Criterios de aceptación:

+ Dado un ESP32 encendido        
  Cuando se le asigna un servidor de Integracion Continua      
  Entonces el ESP32 se debe conectar con el servidor por WIFI    

## 5. Aviso de desconexión  
La baliza deberá destacar su desconexión con un color distinto a los demás, por ejemplo, Naranja.

### Criterios de aceptación:

+ Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
  Cuando se pierda la conexion por WiFi    
  Entonces el ESP32 debe encender el led naranja de la baliza  

## 6. Configuración de WiFi     
La baliza deberá permitir configurar la red y credenciales para conectarse a WiFi.

### Criterios de aceptación:

## 7. Configuración de build      
La baliza deberá permitir configurar la url del build monitoreado y las credenciales de acceso al sistema de Integración Continua.  

### Criterios de aceptación:

## 8. Agregar Herramienta de Integración Continua    
La baliza deberá permitir agregar conectores para nuevas herramientas de Integración Continua.

### Criterios de aceptación:
