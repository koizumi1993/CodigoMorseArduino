/*
  Morse Code Project (Variacion para introducir cadenas por el Monitor Serie )
  
  Este codigo recorre una cadena de caracteres introducida por el Monitor Serie y los transforma en codigo morse.  
  La salida hace que se iluminen dos leds y suene un pitido largo o corto por un zumbador piezoelectrico.  
 */


// creamos las variables para los pines de salida
int led12 = 12;      // parpadea un led en la salida del pin 12
int led6 = 6;        // parpadea un led en la salida del pin 6
int audio8 = 8;      // salida de audio en el pin 8
int note = 1200;      // nota inicial-Periodo de la onda

/*
 Ajustamos la velocidad del codigo morse (dot=>punto ; dash=>raya)
 Ajustamos 'dotlen'= 'duracion del punto' que es la duracion del tono y responsable de la velocidad de nuestro codigo 
  (todo el resto de duraciones estan relacionadas con 'dotlen')

 Estas son las relaciones de duracion del tono de los distintos elementos en codigo morse:
   duracion raya = duracion punto x 3
   Pausa entre elementos = duracion punto
    (pausa entre elementos de un caracter)
   Pausa entre caracteres = duracion punto x 3
   Pausa entre palabras = duracion punto x 7
            Informacion extraida de aqui:
            
            http://www.nu-ware.com/NuCode%20Help/index.html?m...
*/
int dotLen = 100;     // Duracion del codigo morse 'punto'
int dashLen = dotLen * 3;    // Duracion del codigo morse 'raya'
int elemPause = dotLen;  // Duracion de la pausa entre elementos de un caracter
int Spaces = dotLen * 3;     // Duracion del espacio entre caracteres
int wordPause = dotLen * 7;  // Duracion de la pausa entre palabras


// el 'setup' se realiza una vez que pulses el boton de 'reset'
void setup() {                
  //Inicializamos los pines digitales para las salidas de los diodos led 
  pinMode(led12, OUTPUT); 
  pinMode(led6, OUTPUT); 
  Serial.begin(9600);
}

// Creamos un loop para recorrer la cadena definida en la parte superior del codigo 

void loop(){ 
  // si hay caracteres los leemos en orden hasta que se agote la cadena. 
  // Entonces finaliza el loop
  if (Serial.available() > 0) {
   char i = Serial.read();
    
        // Leemos el caracter
 char tmpChar = i;
 // Lo transformamos en minuscula
 tmpChar = toLowerCase(tmpChar);
 // Llamamos a la funcion correspondiente en codigo morse para este caracter
 GetChar(tmpChar);   
  }
}
// PUNT (PUNTO)
void MorseDot()
{
  digitalWrite(led12, HIGH);   // Encendemos el led
  digitalWrite(led6, HIGH);     // Encendemos el led
  tone(audio8, note, dotLen); // hacemos sonar una nota en el zumbador
  delay(dotLen);              // mantenemos este estado
}

// DASH (RAYA)
void MorseDash()
{
  digitalWrite(led12, HIGH);   // Encendemos el led
  digitalWrite(led6, HIGH);     // Encendemos el led
  tone(audio8, note, dashLen); // hacemos sonar una nota en el zumbador
  delay(dashLen);               // mantenemos este estado
}

// Apagado
void LightsOff(int delayTime)
{
  digitalWrite(led12, LOW);     // Apagamos el led   
  digitalWrite(led6, LOW);      // Apagamos el led  
  noTone(audio8);         // silenciamos el zumbador
  delay(delayTime);             // mantenemos este estado
}

// * Listado de caracteres para la conversion a codigo morse * //
void GetChar(char tmpChar)
{
 // Cogemos el caracter pasado por el loop que recorre la cadena, 
        // y hacemos un 'switch case' para encontrar la funcion correspondiente al codigo morse de ese caracter.
 switch (tmpChar) {
   case 'a': 
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'b':
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'c':
     MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'd':
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'e':
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'f':
     MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'g':
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'h':
     MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'i':
     MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'j':
     MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
      case 'k':
     MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'l':
     MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
      case 'm':
     MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'n':
     MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'o':
     MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'p':
     MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 'q':
     MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'r':
     MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 's':
     MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   case 't':
     MorseDash();
  LightsOff(elemPause);
  break;
   case 'u':
     MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'v':
     MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'w':
     MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'x':
     MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'y':
     MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  break;
   case 'z':
     MorseDash();
  LightsOff(elemPause);
  MorseDash();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  MorseDot();
  LightsOff(elemPause);
  break;
   default: 
  // Si un caracter no se encuentra en la tabla, se deja un espacio en blanco
  LightsOff(Spaces);   
 }
}
