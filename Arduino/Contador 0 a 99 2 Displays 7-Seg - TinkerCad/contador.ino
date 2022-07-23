/**
 *******************************************
 *  Contador com 2 Displays Multiplexados  *
 *******************************************
 *
 * Autor: João Pedro Iacillo Soares
 * Turma: 3151
 * Data: 15/04/2022
 * Matéria: Lab. Eletrônica Especializada
 */


/*** Constantes e Variáveis ***/

/// O tempo de atraso entre cada incrementação do número atual.
const int incrementDelay = 5; 	// ms

/// O tempo que o display ficará aceso até ir para o próximo.
const int displayDelay = 100; 	// ms

/// Número a ser impresso nos displays.
int currentNumber = 0;

/// Holder para a unidade do número atual.
int unit;
/// Holder para a dezena do número atual.
int dozen;


/// Os segmentos do display.
const int leds[] = { 13, 12, 11, 10, 9, 8, 7 };

/// Os transistores conectados ao comum dos displays.
const int transistors[] = { 5, 4 };

/// Lista de caracteres impressos nos displays.
const int chars[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}, // 9
};


/*** Índices ***/

int i_l;
int i_t;
int i_r;


/*** Configurações ***/

void setup()
{
	for (i_l = 0; i_l < 7; i_l++)
		pinMode(leds[i_l], OUTPUT);
	
	for (i_t = 0; i_t < 2; i_t++)
		pinMode(transistors[i_t], OUTPUT);
}


/*** Funções ***/

/// Escreve um caractére específico da lista de caractéres nos
/// pinos dos segmentos.
void writeChar(int charIndex)
{
	for (i_l = 0; i_l < 7; i_l++)
		digitalWrite(leds[i_l], chars[charIndex][i_l]);
}

/// Pisca o display atual por um tempo específico.
///
/// Possibilita a escrita de caractéres diferentes em displays
/// multiplexados.
void blinkDisplay()
{
	digitalWrite(transistors[i_t], HIGH);
	delay(displayDelay);
	digitalWrite(transistors[i_t], LOW);
}

void writeCharToDisplay(int charIndex)
{
  	writeChar(charIndex);
	blinkDisplay();
}


/*** Programa ***/

void loop()
{
	unit = currentNumber % 10;
	dozen = currentNumber / 10;
	
  	// Repete os mesmos caractéres tantas vezes para que os
  	// números possam ser lidos com mais facilidade.
  	for (i_r = 0; i_r < incrementDelay; i_r++)
    {
      i_t = 0;
      writeCharToDisplay(unit);
      i_t++;
      writeCharToDisplay(dozen);
    }
  
  	currentNumber++;
  	if (currentNumber == 100)
    {
      currentNumber = 0;
    }
}
