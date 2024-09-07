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

**R\:** Basicamente lo que hace el codigo es que si se escribe por consola el número 1 va a parecer en la pantalla el mensaje "Hello from Raspberry Pi Pico"

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
  
**R\:** Son importantes dado que PortName es la función que le da el nombre al puerto, en otras palabras es la función que le indica al programa que puerto es el que se va a usar.Por otro lado, BaudRate basicamente cumple la función de indicar la velocidad con la que se va a hacer la trsnamisión de datos

- ¿Qué relación tienen las propiedades anteriores con el controlador?

**R\:** Como se enciono anteriormente PortName sirve para indicar en que puesto se encuentra conectado el controlador y BaudRate es quien indica la velocidad quen tendra la transmisión de datos entre el controlador y el computador.

## Ejercicio 2

Te invito a ver antes unos videos cortos con la explicación de este experimento usando unas herramientas un poco diferentes, sin embargo, el principio es el mismo.  Te dejo [este](https://youtube.com/playlist?list=PLX4ZVWZsOgzST9kfU9_ohOUYp_oDo2z48) link).

Ahora realiza este experimento. Modifica la aplicación del PC así:

```
using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Serial : MonoBehaviour
{
	private SerialPort _serialPort =new SerialPort();
	private byte[] buffer =new byte[32];

	public TextMeshProUGUI myText;

	private static int counter = 0;

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
        myText.text = counter.ToString();
        counter++;

				if (Input.GetKeyDown(KeyCode.A))
        {
            byte[] data = {0x31};// or byte[] data = {'1'};            
						_serialPort.Write(data,0,1);
            int numData = _serialPort.Read(buffer, 0, 20);
            Debug.Log(System.Text.Encoding.ASCII.GetString(buffer));
            Debug.Log("Bytes received: " + numData.ToString());
        }
    }
}
```

En tu sistema operativo debes averiguar en qué puerto está el controlador y cómo se llama. En Windows se usa COMx, donde x es el número del puerto serial asignado por el sistema operartivo a tu controlador.

A continuación, debes adicionar a la aplicación un elemento de GUI tipo *Text - TextMeshPro* y luego, arrastrar una referencia a este elemento a *myText* (si no sabes cómo hacerlo llama al profe).

Y la aplicación del controlador:

```
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

**R\:** El codigo inicia un contador que va muy pero muy rapido y cuando oprimimos la letra A este suma un byte, cada vez que pulsemos A se agregara un byte.

Prueba con el siguiente código. Luego, **ANALIZA CON DETENIMIENTO.** Una vez más, no olvides cambiar el puerto serial.

```csharp
using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Serial : MonoBehaviour
{
		private SerialPort _serialPort =new SerialPort();
		private byte[] buffer =new byte[32];

		public TextMeshProUGUI myText;

		private static int counter = 0;

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
        myText.text = counter.ToString();
        counter++;

				if (Input.GetKeyDown(KeyCode.A))
				{
            byte[] data = {0x31};// or byte[] data = {'1'};
            _serialPort.Write(data,0,1);
        }
				if (_serialPort.BytesToRead > 0)
			  {
	          int numData = _serialPort.Read(buffer, 0, 20);
            Debug.Log(System.Text.Encoding.ASCII.GetString(buffer));
            Debug.Log("Bytes received: " + numData.ToString());
        }
		}

```

¿Funciona?
Por ejemplo, ¿Qué pasaría si al momento de ejecutar la instrucción `int numData = 
_serialPort.Read(buffer, 0, 20);` solo han llegado 10 de los 16 bytes del mensaje? ¿Cómo puede hacer tu programa para saber que ya tiene el mensaje completo? ¿Cómo se podría garantizar que antes de hacer la operación Read tenga los 16 bytes listos para ser leídos? Además, si los mensajes que envía el controlador tienen tamaños diferentes, ¿Cómo haces para saber que el mensaje enviado está completo o faltan bytes por recibir?

**R\:** El codigo si funciona, este basicamente va haciendo un conteo de los bytes que hay en el momento hasta llegar a 20. Cuando el sistema no llega a los 20 bytes lo que hace es contar hasta el número que haya, si hay 916 bytes cuenta hasta 16 bytes, si hay más contara más y si hay menos contara menos. En cuanto al buffer eso depende de como se programe se puede decidir que comience en 0 o 10 y que termine hasta en 50, depende de quien lo programe.
