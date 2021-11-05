# Presentacion IoT: Esp32 + MQTT + NodeRed - 1 Nov 2021 - Eduardo Martinez
## Documentos

###  proj-42-mqtt2.pdf:

Diagrama de como están construídos los módulos del programa

###  ESP32.ppt

Filminas proyectadas para explicar ESP32

###  MQTT.ppt

Filminas proyectadas para explicar MQTT

### Diagrama-MQTT-20211101.pdf

Diagrama MQTT del ejemplo que se presentó en clase

Incluye las dos placa con ESP32 y los dos dashboards en node-red
cuyos flujos se incluyen a continuación denominados:

* esp32-dash1.json
* esp32-dash2.json

###  Flujos (flows) de node-red presentados

En cada uno de estos archivos se encuentran los siguientes flujos

* HelloWorld.json:  ejemplo sencillo de un flujo que presenta 'Hello World'
* mqtt.json:        muestra como trabajar con un broker MQTT desde node-red
* BlinkLed.json:    primer ejemplo con un elemento de dashboard: un led   (ver nota mas abajo)
* BAWeather.json:   ejemplo completo de presentar el estado del tiempo desde un servidor
                    que se puede preguntar el mismo (en este caso el de la Ciudad de Buenos Aires)
                    y presentarlo en un dashboard
* esp32-dash1.json: Ejemplo completo para trabajar con el broker MQTT y las placas
                    con ESP32 y el sensor DHT22. Se trata de el flujo de un dashboard
* esp32-dash2.json: Ejemplo completo igual al anterior pero que reside en un node-red
                    que, en el caso del ejemplo que se mostro, residia en un celular

#### Nota: para hacer luego de cargar y poner a funcionar node-red

Para seguir el ejemplo completo mostrado en clase, luego de cargar y ejecutar node-red
en ambas computadoras, se deben cargar los nodos de dashboard, ya que no vienen instalados
por default y, en el caso de lo que yo construi, ademas hay que agregar un nodo dentro de
dashboard para generar leds

* Para agregar los nodos de dashboard: desde node-red cargar -> node-red-dashboard
* Para agregar el nodo de led dentro de dashboard: desde node-red cargar -> node-red-contrib-ui-led

