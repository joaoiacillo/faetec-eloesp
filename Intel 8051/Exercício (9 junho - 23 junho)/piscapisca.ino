/********************************
** Variáveis Globais          **
 ********************************/

byte i, j;


/********************************
 ** Next Button                **
 ********************************/

const byte nxtBtnPin = 10;

bool nxtBtnState, btnPressNoticed;

/**
 * Retorna true uma vez que o botão for pressionado.
 */
void tryToNoticeButton()
{
  nxtBtnState = digitalRead(nxtBtnPin);
  
  if (btnPressNoticed && !nxtBtnState)
  {
    btnPressNoticed = true;
  }
}

void unnoticeButton() {
  btnPressNoticed = false;
}


/********************************
 ** LEDs                       **
 ********************************/

/**
 * Um array contendo os pinos conectados aos LEDs.
 */
const byte ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

const byte ledPinsSize = 8;

/**
 * Apaga todos os LEDs.
 */
void resetAllLeds()
{
  for (j = 0; j < ledPinsSize; j++) digitalWrite(ledPins[j], LOW);
}

/**
 * Seta o pino de LED com o valor especificado.
 */
void setPin(byte pin, bool value)
{
  digitalWrite(ledPins[pin], value);
}

/**
 * Liga um LED específicado pelo parâmetro pin.
 */
void turnOn(byte pin)
{
  digitalWrite(ledPins[pin], HIGH);
}

/**
 * Desliga um LED específicado pelo parâmetro pin.
 */
void turnOff(byte pin)
{
  digitalWrite(ledPins[pin], LOW);
}


/********************************
 ** Configurações              **
 ********************************/

void setup()
{
  Serial.begin(9600);
  for (i = 0; i < ledPinsSize; i++) pinMode(ledPins[i], OUTPUT);
  pinMode(nxtBtnPin, INPUT);
}


/********************************
 ** Programa                   **
 ********************************/

void loop()
{
  tryToNoticeButton();
  if (btnPressNoticed) {
    Serial.println("Pressed");
    resetAllLeds();
    nextEffect();
    unnoticeButton();
  }

  playCurrentEffect();
}


/********************************
 ** Efeitos                    **
 ********************************/

/**
 * Guarda o efeito selecionado no momento.
 */
byte currentEffect = 0;

/**
 * Avança para o próximo efeito da lista.
 */
void nextEffect()
{
  currentEffect++;
}

/**
 * Executa a função do efeito atual.
 */
void playCurrentEffect()
{
  switch(currentEffect)
  {
    case 0:
      effect0();
      break;
    case 1:
      effect1();
      break;
    case 2:
      effect2();
      break;
    case 3:
      effect3();
      break;
    case 4:
      effect4();
      break;
    case 5:
      effect5();
      break;
    case 6:
      effect6();
      break;
    case 7:
      effect7();
      break;
  }
}

void effect0()
{
  for (i = 0; i < ledPinsSize; i++) setPin(i, i % 2 == 0);
  delay(500);
  for (i = 0; i < ledPinsSize; i++) setPin(i, i % 2 != 0);
  delay(500);
}

void effect1()
{
  
}

void effect2()
{
  
}

void effect3()
{
  
}

void effect4()
{
  
}

void effect5()
{
  
}

void effect6()
{
  
}

void effect7()
{
  
}
