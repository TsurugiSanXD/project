## ¿Qué escenarios podría tener en este caso?

```
if(Serial.available() >= 2){
    int dataRx1 = Serial.read()
    int dataRx2 = Serial.read()
    int dataRx3 = Serial.read()
}
```

A comparación del primer caso este escenario podria cometer errores. al declarara que Serial.avaliable() >= 2 y despues darle una posible lestura de 3 bytes, cuando llegue al 3 despues de haber almacenado el byte 1 y 2 intenta leer el byte 3 pero este no se ha verificado si realmente hay un tercer byte disponible dado que en la condición solo establecimos la verificación de 2 bytes. Teniendo en cuenta lo anteror, lo que podria pasar es que podria funcionar aunque la condisión sea ligeramente erronea ya que realmente necesitas 3 bytes, o tambien esta el caso en que al intentar leer buffer este encuentre que no hay más bytes disponibles y devuelva un -1, almacenandolo en dataRx3(siendo esto tal vez no deseado).
