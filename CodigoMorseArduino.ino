char mensaje[] = "Hola Mundo";

// Create variable to define the output pins
int ledVerde = 12;      // blink an led on output 12
int ledRojo = 6;        // blink an led on output 6
int zumbador = 8;      // output audio on pin 8
int nota = 1200;      // music note/pitch


int tamPunto = 100;     // length of the morse code 'dot'
int tamLinea = tamPunto * 3;    // length of the morse code 'dash'
int pausas = tamPunto;  // length of the pause between elements of a character
int espacios = tamPunto * 3;     // length of the espacios between characters
int pausasPalabra = tamPunto * 7;  // length of the pause between words

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output for LED lights.
  pinMode(ledVerde, OUTPUT); 
  pinMode(ledRojo, OUTPUT); 
}

// Create a loop of the letters/words you want to output in morse code (defined in string at top of code)
void loop()
{ 
  // Loop through the string and get each character one at a time until the end is reached
  for (int i = 0; i < sizeof(mensaje) - 1; i++)
  {
    // Get the character in the current position
  char caracTmp = mensaje[i];
  // Set the case to lower case
  caracTmp = toLowerCase(caracTmp);
  // Call the subroutine to get the morse code equivalent for this character
  GetChar(caracTmp);
  }
  
  // At the end of the string long pause before looping and starting again
  apagadoLuces(8000);      
}

// DOT
void puntosMorse()
{
  digitalWrite(ledVerde, HIGH);    // turn the LED on 
  digitalWrite(ledRojo, HIGH); 
  tone(zumbador, nota, tamPunto); // start playing a tone
  delay(tamPunto);              // hold in this position
}

// DASH
void lineasMorse()
{
  digitalWrite(ledVerde, HIGH);    // turn the LED on 
  digitalWrite(ledRojo, HIGH);
  tone(zumbador, nota, tamLinea);  // start playing a tone
  delay(tamLinea);               // hold in this position
}

// Turn Off
void apagadoLuces(int delayTime)
{
  digitalWrite(ledVerde, LOW);     // turn the LED off   
  digitalWrite(ledRojo, LOW);
  noTone(zumbador);             // stop playing a tone
  delay(delayTime);             // hold in this position
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char caracTmp)
{
  // Take the passed character and use a switch case to find the morse code for that character
  switch (caracTmp) {
    case 'a': 
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'b':
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'c':
      lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'd':
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'e':
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'f':
      puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'g':
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'h':
      puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'i':
      puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'j':
      puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
      case 'k':
      lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'l':
      puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
      case 'm':
      lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'n':
      lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'o':
      lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'p':
      puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 'q':
      lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'r':
      puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 's':
      puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    case 't':
      lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'u':
      puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'v':
      puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'w':
      puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'x':
      lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'y':
      lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    break;
    case 'z':
    lineasMorse();
    apagadoLuces(pausas);
    lineasMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    puntosMorse();
    apagadoLuces(pausas);
    break;
    default: 
    // If a matching character was not found it will default to a blank space
    apagadoLuces(espacios);      
  }
}
