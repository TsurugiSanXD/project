## Unidada 3.

## Ejercicio 1.

*¿Cómo se ve un protocolo binario?*
*R?\:* El codigo binario es la comunicación que hay entre el dispositivo de salida y el recepto, basicamente, como el controlador se ejecuta y de vuelve la información al programa.

*¿Puedes describir las partes de un mensaje?*
*R?\:* Las partes del mensaje se dividen en 6, estas partes son: Len, Adr, Cmd, Data[], LSB-CRC16 Y MSB-CRC16

*¿Para qué sirve cada parte del mensaje?*
len: determina la longitud de la cadena de caracteres (de Data[]) en el protocolo.

adr: identifica el dispositivo receptor.

cmd: consola de comandos, se usa para interacvtuar con el sistema en el protocolo binario.

Data[]: conjunto de datos que se transmitiran en el protocolo binario, si no hay datos, el peso del data[] sera 0.

LSB-CRC16 Y MSB-CRC16: confirman que el mensaje no tenga errores al moento de enviarse.

## Ejercicio 4.

*¿En qué endian estamos transmitiendo el número?*
*R?\:* Los datos se estan leyendo en little endian, esto lo sabemos dado que al declarar el puntero en la linea " Serial.write ( (uint8_t *) &num,4);" le estamos indicando que lea los bytes que conforma el número del menor al mayor.

*Y si queremos transmitir en el endian contrario, ¿Cómo se modifica el código?*
*R?\:* Como se muestra en el codigo para presentar los datos en el endian contrario lo que podemos hacer es crear un bucle en el cual indiquemos que la lectura del puntero de se hara de manera contraria.{

## Ejercicio 5.

```
void setup() {
    Serial.begin(115200);
}

void loop() {
    float num1 = 4206.9023;
    float num2 = 3450;
    

    uint8_t arr1[4] = {0};
    uint8_t arr2[4] = {0};


    memcpy(arr1, (uint8_t *)&num1, 4);
    memcpy(arr2, (uint8_t *)&num2, 4);


    if(Serial.available())
    {
      if(Serial.read() == 'l')
      {
       Serial.println("Little-endian:");
          for (int i = 0; i < 4; i++) 
          {
              Serial.write(arr1[i]);
          }
        Serial.println();
       for (int i = 0; i < 4; i++) 
       {
           Serial.write(arr2[i]);
       }
       Serial.println();
      }
      else
      if(Serial.read() == 'b')
      {
           Serial.println("Big-endian:");
             for (int i = 3; i >= 0; i--) 
             {
              Serial.print(arr1[i]);
             }
           Serial.println();
             for (int i = 3; i >= 0; i--) 
             {
              Serial.print(arr2[i]);
             }
       Serial.println();
      }



    }

}
```


