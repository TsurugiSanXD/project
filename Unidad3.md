## Unidada 3.

## Ejercicio 1.

*¿Cómo se ve un protocolo binario?*
*R?\:* El codigo binario es la comunicación que hay entre el dispositivo de salida y el recepto, basicamente, como el controlador se ejecuta y de vuelve la información al programa.

*¿Puedes describir las partes de un mensaje?*
*R?\:* Las partes del mensaje se dividen en 6, estas partes son: Len, Adr, Cmd, Data[], LSB-CRC16 Y MSB-CRC16

## Ejercicio 4.

*¿En qué endian estamos transmitiendo el número?*
*R?\:* Los datos se estan leyendo en little endian, esto lo sabemos dado que al declarar el puntero en la linea " Serial.write ( (uint8_t *) &num,4);" le estamos indicando que lea los bytes que conforma el número del menor al mayor.

*Y si queremos transmitir en el endian contrario, ¿Cómo se modifica el código?*
*R?\:* Como se muestra en el codigo para presentar los datos en el endian contrario lo que podemos hacer es crear un bucle en el cual indiquemos que la lectura del puntero de se hara de manera contraria.



