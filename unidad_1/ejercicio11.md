## ¿Por qué enviaste la letra con el botón send? ¿Qué evento verifica si ha llegado algo por el puerto serial?
Primero enviamos la letra con el botón "send" al detectar ese valor, este lo busca y lo asigna a serial.avaliable; ahí tenemos la función "if (Serial.available() > 0)", este tiene la función de detectar si hay alguna techa presionada que contenga un valor, envia el mensaje, en cambio si no hay ninguna tecla presionada no mandara ningun mensaje.

## Abre esta tabla.
En la tabla muestra la correspondencia entre caracteres y sus valores numéricos en la codificación ASCII.

## Analiza los números que se ven debajo de las letras. Nota que luego de la r, abajo, hay un número. ¿Qué es ese número?
Cada letra en la tabla es un codigo ASCII. Cada valor se vuelve un número y despues en se transforma en lenguaje maquina; la r esta en el apartado Chr y va acompañado del 72 en Hx, del 162 en Oct, 114 en Dec y &#114 en Html.

## ¿Qué relación encuentras entre las letras y los números?
Basicamente, cada letra tiene un codigo directo en ASCII; este codigo es lo que se envia y se procesa cuando se transmite un caracter a través del puerto serial.

## ¿Qué es el 0a al final del mensaje y para qué crees que sirva?
El 0a es el código hexadecimal para el carácter de nueva línea, utilizamos 0a para indicar el final de una linea de texto y dar un salto a la siguiente linea de texto.
