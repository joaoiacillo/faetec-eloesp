const byte BTN = 3;
const byte LED1 = 4;
const byte LED2 = 5;

bool btnState = 0;

void setup()
{
  pinMode(BTN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  btnState = digitalRead(BTN);
  
  if (btnState == HIGH) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
  delay(10);
}