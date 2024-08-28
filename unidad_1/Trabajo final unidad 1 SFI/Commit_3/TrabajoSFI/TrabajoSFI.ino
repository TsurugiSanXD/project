void program()
{
  enum class Estados // Todos los estados en el diagrama
  {
    CONFIG_TIEMPO,
    TIEMPO_S,
    TIEMPO_B,
    INICIO_CUENTA,
    SALVASTE,
    RADIACION
  };

  static Estados evento = Estados::CONFIG_TIEMPO; // Variables como el cambio de estados
  static bool mensaje = false; // Para mensajes y evitar un bucle de muchos mensajes
  static char serial; // Para pasar los datos leídos en el monitor serial
  static int segundo = 1000; // Para aumentar el tiempo
  static int contador = 5 * 1000; // Contador para almacenar el tiempo


  switch(evento)
  {
    case Estados::CONFIG_TIEMPO:
    {
      if(mensaje == false) // If con condición de mensaje en falso, para que entre una sola vez y luego se vuelva verdadero
      {
        Serial.print("Modo configuración activado");
        Serial.println("El tiempo actual es de: ");
        Serial.print(contador/1000);
        Serial.print(" segundos");
        Serial.println("Ingrese S para subir un segundo, B para bajar un segundo o L para terminar");
        mensaje = true;
      }

      if(Serial.available() > 0) // Revisar serial, y luego leerlo para comparar su resultado
      {
        serial = Serial.read();
        if(serial == 'S' || serial == 's')
        {
          evento = Estados::TIEMPO_S;
        }
        else if(serial == 'B' || serial == 'b')
        {
          evento = Estados::TIEMPO_B;
        }
        else if(serial == 'L' || serial == 'l')
        {
          evento = Estados::INICIO_CUENTA;
        }
      }
      break;
    }

    case Estados::TIEMPO_S:
    {
      if(contador < 40000) // Si el contador es menor a 40 aumentar en uno y devolver a la configuración, también volvemos el mensaje false para que entre al if anterior
      {
        contador += segundo;
        mensaje = false;
        evento = Estados::CONFIG_TIEMPO;
      }
      else // Si es 40 ya no agregará más
      {
        Serial.println("No se puede aumentar más el tiempo");
        mensaje = false;
        evento = Estados::CONFIG_TIEMPO;
      }
      break;
    }

    case Estados::TIEMPO_B: // Muy similar a la función Tiempo_S pero al revés
    {
      if(contador > 1000)
      {
        contador -= segundo;
        mensaje = false;
        evento = Estados::CONFIG_TIEMPO;
      }
      else if(contador == 1000)
      {
        Serial.println("No se puede disminuir más el tiempo");
        mensaje = false;
        evento = Estados::CONFIG_TIEMPO;
      }
      break;
    }

    case Estados::INICIO_CUENTA: // Resta el tiempo hasta 0
    {
      
   
        if(contador > 0) // Solo se sigue si el contador es mayor que 0
        {
          delay(1000);
          contador -= segundo;
          Serial.print("Tiempo restante: ");
          Serial.println(contador/1000);
        }
        else
        {
          evento = Estados::RADIACION; // Cambia al siguiente estado cuando el tiempo llegue a 0
        }
      

      if(Serial.available() > 0) // Revisa que en el serial esté el código
      {
        String code = "";
        while(Serial.available() > 0) // Revisa todo el buffer y va añadiendo los valores uno a uno
        {
          code += (char)Serial.read(); 
        }

        if(code == "C1234") // Si se ingresa el código correctamente salta a salvar el mundo
        {
          evento = Estados::SALVASTE;
        }
      }
      break;
    }

    case Estados::SALVASTE:
    {
      Serial.println("Salvaste al mundo"); // Mensaje de que se salvó el mundo y termina el código
      exit(0);
    }

    case Estados::RADIACION:
    {
      Serial.println("Radiación nuclear activa"); // Mensaje de que no se pudo salvar el mundo, pausa de 2 seg, y vuelve a iniciar
      mensaje = false;
      delay(2000);
      evento = Estados::CONFIG_TIEMPO;
    }
  }
}

void setup() 
{
  Serial.begin(115200); //Cantidad de datos que se pueden leer por segundos
  delay(3000);
  program();
}

void loop() 
{
  program();
}
