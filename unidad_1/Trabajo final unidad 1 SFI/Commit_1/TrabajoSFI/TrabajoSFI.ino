void program()
{
  enum class Estados //Todos los estados en el diagrama
  {
    CONFIG_TIEMPO,
    TIEMPO_S,
    TIEMPO_B,
    INICIO_CUENTA,
    SALVASTE,
    RADIACION

  };
  static Estados evento = Estados::CONFIG_TIEMPO; //Variables como, el cambio de estados
  static bool mensaje = false; //Para mensajes y evitar un bucle de muchos mensajes
  static char serial; //Para pasar los datos leídos en el monitor serial
  static int segundo = 1000; //Para aumentar el tiemmpo
  static int contador = 5 * 1000; //Contador para almacenar el tiempo

  switch(evento)
  {
    case Estados::CONFIG_TIEMPO:
    {
      
      if(!mensaje) //If con condición de mensaje en falso, para que entre una sola vez y leugo se vuelva verdadero
      {
        Serial.print("Modo configuración activado");
        Serial.println("El tiempo actual es de: ");
        Serial.print(contador/1000);
        Serial.print(" segundos");
        Serial.println("Ingrese S para subir un segundo, B para bajar un segundo o L para terminar");
        
        mensaje = true;
      }

      if(Serial.available()) //Revisar serial, y luego leerlo para comparar su resultado
      {
        serial = Serial.read();
        if(serial == 'S' || serial == 's')
        {
          evento = Estados::TIEMPO_S;
        }
      }
      break;
    }
    case Estados::TIEMPO_S:
    {
      if(contador < 40000) //SI el contador es menor a 40 aumentar en uno y devolver a la configuración, también volvemos el mensaje false para que entre al if anterior
      {
        contador += segundo;
        mensaje = false;
        evento = Estados::CONFIG_TIEMPO;
      }
      else //Si es 40 ya no aagregará más
      {
        Serial.println("No se puede aumentar más el tiempo");
        mensaje = false;
        evento = Estados::CONFIG_TIEMPO;
      }
      
      break;
    }
  }
  
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  program();

}

void loop() 
{
  // put your main code here, to run repeatedly:
  program();
}
