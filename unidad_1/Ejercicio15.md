## ¿Por qué es necesario declarar rxData static? y si no es static ¿Qué pasa? ESTO ES IMPORTANTE, MUCHO.
Es necesario dado que si la variable rxData no fuera static, el valor de esta se reiniciaria cada qvez que la variable fuera llamada, perdiendo la información al regresar al loop y volver a llamar a Task()1

## dataCounter se define static y se inicializa en 0. Cada vez que se ingrese a la función loop dataCounter se inicializa a 0? ¿Por qué es necesario declararlo static?
Datacounte no se inicializa en 0 cada vez se entra al loop. Al ser static, datacounter conserva su valor cada vez se llama al task1. Como se menciono en la respuesta anterior es necesario que se mantenga static dado que esto permite conservar la información , si no fuera static se reiniciaria a 0 cada vez que se llama al task1.

## Finalmente, la constante 0x30 en (pData[i] - 0x30) ¿Por qué es necesaria?
Lo que pasa es que cuando enviamos un número a través del puerto serial este se envia como un caracter. Ejemplo: si envias el número 5 lo que en realidad estas enviando es el caracter 5 que representa el valor 0x35 en hexadecimal; teniendo esto en cuenta, antes de enviar un número tenemos que convertirlo si queremos realizar operaciones matematicas con este, en ese momento es que entra la formula pData[i] - 0x30 que es la que nos ayuda a ahcer esta conversión. Entonces, para poder usar el número 5 como un valor y no un caracter lo que deberiamos hacer es usar la formula así: pData[i] - 0x35.
