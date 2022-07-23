const byte leds[] = { 13, 12, 11, 10, 9, 8, 7, 6 };

const int blinkDelay = 50;

int i, j;

/*** Configuração ***/

void setup()
{
	for (i = 0; i < 8; i++) pinMode(leds[i], OUTPUT);
}

/*** Funções ***/

void blinkLed(int pin)
{
	delay(blinkDelay);
	digitalWrite(pin, HIGH);
	delay(blinkDelay);
	digitalWrite(pin, LOW);
}

void fall()
{
	for (j = 7 - i; j >=0; j--)
	{
		blinkLed(leds[j]);
	}
}

void bounce()
{
	for (j = 0; j <= 6 - i; j++)
	{
		blinkLed(leds[j]);
	}
}

/*** Programa ***/

void loop()
{
	for (i = 0; i < 8; i++)
	{
		fall();
		bounce();
	}
	digitalWrite(leds[7], LOW);
	delay(2000);
}
