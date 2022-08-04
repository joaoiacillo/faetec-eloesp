const byte leds[] = { 7, 6, 5 };
const byte pot = A2;
const byte vled = 3;
const byte btn = 2;
const byte leds_len = sizeof(leds) / sizeof(leds[0]);
const unsigned long delay_time = 100;

short pot_read;
short velocity = 100;

volatile int i;

void setup()
{
  for (i = 0; i < leds_len; i++) pinMode(leds[i], OUTPUT);
  i = 0;

  attachInterrupt(digitalPinToInterrupt(btn), itr_btn, FALLING);
	Serial.begin(9600);
}

void loop()
{
  readPot();
  lightUpVLed();
  loopLeds();
}

void friendlyDelay(unsigned long t)
{
  while (t > 0) {
    t--;
    Serial.println(t);
  }
}

void itr_btn()
{
  friendlyDelay(delay_time);
  i = 0;
  clearLeds();
}

void lightUpVLed()
{
  analogWrite(vled, pot_read / 4);
}

void readPot()
{
  pot_read = analogRead(pot);
  velocity = map(pot_read, 0, 1023, 100, 2000);
}

void clearLeds()
{
  for (i = 0; i < leds_len; i++) digitalWrite(leds[i], LOW);
  i = 0;
}

void loopLeds()
{
  if (i >= leds_len)
  {
    i = 0;
    clearLeds();
    delay(velocity);
  }
  digitalWrite(leds[i], HIGH);
  i++;
  delay(velocity);
}
