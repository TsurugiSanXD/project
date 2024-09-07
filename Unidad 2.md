## Ejercicio 1
```
void setup() {
  Serial.begin(115200);
}

void loop() {
if(Serial.available()){
if(Serial.read() == '1'){
      Serial.print("Hello from Raspberry Pi Pico");
    }
  }
}
```
Prueba la aplicación con ScriptCommunicator. ¿Cómo funciona?
R\: Basicamente lo que hace el codigo es que si se escribe por consola el número 1 va a parecer en la pantalla el mensaje "Hello from Raspberry Pi Pico"

Crea un nuevo C# Script y un Game Object. Añade el Script al GameObject. Ve al menu Assets y luego selecciona Open C# Project.

```csharp
using UnityEngine;
using System.IO.Ports;
public class Serial : MonoBehaviour
{
private SerialPort _serialPort =new SerialPort();
private byte[] buffer =new byte[32];

void Start()
    {
        _serialPort.PortName = "COM3";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable =true;
        _serialPort.Open();
        Debug.Log("Open Serial Port");
    }

void Update()
    {

				if (Input.GetKeyDown(KeyCode.A))
        {
            byte[] data = {0x31};// or byte[] data = {'1'};            
						_serialPort.Write(data,0,1);
            Debug.Log("Send Data");
        }

				if (Input.GetKeyDown(KeyCode.B))
        {
						if (_serialPort.BytesToRead >= 16)
            {
                _serialPort.Read(buffer, 0, 20);
                Debug.Log("Receive Data");
                Debug.Log(System.Text.Encoding.ASCII.GetString(buffer));
            }
        }

    }
}
```

Analiza:

- ¿Por qué es importante considerar las propiedades *PortName* y *BaudRate*?
R\: Son importantes dado que PortName es la función que le da el nombre al puerto, en otras palabras es la función que le indica al programa que puerto es el que se va a usar.Por otro lado, BaudRate basicamente cumple la función de indicar la velocidad con la que se va a hacer la trsnamisión de datos

- ¿Qué relación tienen las propiedades anteriores con el controlador?
R\:Como se enciono anteriormente PortName sirve para indicar en que puesto se encuentra conectado el controlador y BaudRate es quien indica la velocidad quen tendra la transmisión de datos entre el controlador y el computador.

## Ejercicio 2

A continuación, debes adicionar a la aplicación un elemento de GUI tipo *Text - TextMeshPro* y luego, arrastrar una referencia a este elemento a *myText* (si no sabes cómo hacerlo llama al profe).

Y la aplicación del controlador:

```cpp
void setup()
{
		Serial.begin(115200);
}

void loop()
{
		if(Serial.available())
		{
				if(Serial.read() == '1')
				{
			      delay(3000);
			      Serial.print("Hello from Raspi");
				}
		}
}
```

Ejecuta la aplicación en Unity. Verás un número cambiar rápidamente en pantalla. Ahora presiona la tecla A (no olvides dar click en la pantalla *Game*). ¿Qué pasa? ¿Por qué crees que ocurra esto?
R\:

