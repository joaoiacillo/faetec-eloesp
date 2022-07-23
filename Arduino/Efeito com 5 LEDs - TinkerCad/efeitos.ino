/**
 *  Programa Efeitos com 5 LEDS
 *
 *  Nome: João Pedro Iacillo Soares
 *  Turma: 3151
 *  Data: 26/03/2022
 */

/*** Variáveis e Constantes ***/

const int leds[] = { 11, 10, 9, 8, 7 };

const int effect1Delay_1 = 800;
const int effect1Delay_2 = 200;

const int ledsLength = sizeof(leds) / sizeof(int);

int i;

/*** Configurações ***/

/**
 * Função de configuração do Arduino.
 */
void setup() {
  for (i = 0; i < ledsLength; i++)
    pinMode(leds[i], OUTPUT);
}

/*** Funções ***/

/**
 * Pisca um LED.
 *
 * @param led O LED para piscar.
 * @param delayTime O tempo de delay entre cada alteração de estado.
 */
void blinkLed(int led, int delayTime) {
  digitalWrite(led, HIGH);
  delay(delayTime);
  digitalWrite(led, LOW);
  delay(delayTime);
}

/*** Efeito ***/

/**
 * Executa o efeito 1.
 *
 * Mantendo um led sempre aceso, ele vai piscando 
 */
void efeito1() {
  for (i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
    delay(effect1Delay_1);

    for (int j = 0; j < 5; j++) {
      if (i == j) continue;
      blinkLed(leds[j], effect1Delay_2);
    }
    
    digitalWrite(leds[i], LOW);
  }
}

/*** Programa ***/

/**
 * O loop principal do programa.
 */
void loop() {
  efeito1();
}