/**
 * Programa Pisca-LED com Arduino UNO R3
 *
 * Aluno: João Pedro Iacillo Soares
 * Data: 26/03/2022
 */


/*** Variáveis e Constantes de Configuração ***/

/// Os pinos conectados aos LEDs.
const int leds[] = { 8, 7 };

/// O tempo em millisegundos de cada piscada.
const int blinkDelay = 500; // 500ms = 2Hz


/*** Variáveis e Constantes ***/

/// O tamanho da lista de LEDs.
const int ledsLength = sizeof(leds) / sizeof(int);

/// Índece usado pelas estruturas fors para varrer os leds.
int ledIndex;

/*** Configuração ***/

void setup()
{ 
  for (ledIndex = 0; ledIndex < ledsLength; ledIndex++)
    pinMode(leds[ledIndex], OUTPUT);
}


/*** Programa ***/

void loop()
{
  for (ledIndex = 0; ledIndex < ledsLength; ledIndex++)
  {
    digitalWrite(leds[ledIndex], HIGH);
    delay(blinkDelay);
    digitalWrite(leds[ledIndex], LOW);
  }
}