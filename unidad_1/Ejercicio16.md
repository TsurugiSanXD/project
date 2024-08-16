## ¿Qué pasa cuando hago un Serial.available()?
Cuando utilizamos Serial.available(), los que hacemos es mandar al Arduino a verificar cuántos bytes (datos) han llegado y están esperando en el buffer de recepción del puerto serial.

## ¿Qué pasa cuando hago un Serial.read()?
Cuando usamos Serial.read(), mandamos al Arduino a leer el primer byte disponible en el buffer de recepción y para que luego lo devuelva como un valor entero (un número entre 0 y 255).

## ¿Qué pasa cuando hago un Serial.read() y no hay nada en el buffer de recepción?
Si usamos Serial.read() cuando no hay datos disponibles en el buffer de recepción, la función devuelve -1. Esto indica que no había ningún dato para leer en ese momento.

## Un patrón común al trabajar con el puerto serial es este:

```
if(Serial.available() > 0){
    int dataRx = Serial.read()
}
```
## ¿Qué hace este patrón?
El código lo que hace es verificar si hay al menos un byte disponible en el buffer de recepción usando Serial.available(). Si hay datos, se ejecuta Serial.read() para leer el primer byte disponible y almacenarlo en la variable dataRx.

## ¿Cuántos datos lee Serial.read()?
Serial.read() solo puede leer un byte de datos del buffer de recepción cada vez que lo usamos

## ¿Y si quiero leer más de un dato?
Creo que para leer más de un byte, podriamos hacer un bucle que llame a Serial.read() repetidamente hasta que hayas leído todos los datos disponibles(No estoy segura).

## ¿Qué pasa si te envían datos por serial y se te olvida llamar Serial.read()?
Si olvidamos usar Serial.read() después de que Serial.available() indique que hay datos disponibles, esos datos se quedan en el buffer de recepción y pueden suceder dos errores, que el buffer este lleno o que tenga una lectura incorrecta.
