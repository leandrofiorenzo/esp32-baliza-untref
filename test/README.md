# Baliza de Integración Continua con un ESP32.

## Requerimientos:

+ 1) Actualizar estado de la baliza
El estado de la baliza deberá actualizarse ante cada cambio de estado del build.

+ 2) Color asociado a estado
La baliza deberá mostra luz de color de acuerdo al estado del build:
Exitoso => Verde
Fallido => Rojo

+ 3) Aviso de cambio de estado
La baliza deberá destacar el cambio de estado (Exitoso a Fallido o Fallido a Exitoso) con un alarma sonora corta y/o parpadeo de la luz.

+ 4) Conexión a través de WiFi
La baliza deberá conectarse al servidor del sistema de Integración Continua mediante WiFi.

+ 5) Aviso de desconexión
La baliza deberá destacar su desconexión con un color distinto a los demás, por ejemplo, Naranja.

+ 6) Configuración de WiFi
La baliza deberá permitir configurar la red y credenciales para conectarse a WiFi.

+ 7) Configuración de build
La baliza deberá permitir configurar la url del build monitoreado y las credenciales de acceso al sistema de Integración Continua.

+ 8) Agregar Herramienta de Integración Continua
La baliza deberá permitir agregar conectores para nuevas herramientas de Integración Continua.

