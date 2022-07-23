/**
 * Programa Pisca-LED com Arduino UNO R3
 *
 * Aluno: João Pedro Iacillo Soares
 * Data: 26/03/2022
 */


/*** Variáveis e Constantes de Configuração ***/

/// Os pinos conectados aos LEDs.
const int leds[] = { 9, 8, 7 };

/// Os delays usados por cada LED ao estar ligado.
const int ledDelays[] = { 2500, 500, 2000 };


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
  for (ledIndex = ledsLength; ledIndex >= 0; ledIndex--)
  {
    digitalWrite(leds[ledIndex], HIGH);
    delay(ledDelays[ledIndex]);
    digitalWrite(leds[ledIndex], LOW);
  }
}