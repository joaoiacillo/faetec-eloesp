const byte ledPin = 6;
const byte potPin = A0;

short value, mappedValue;
float volts;

void setup()
{
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(potPin);
  mappedValue = map(value, 0, 1023, 0, 255);
  analogWrite(ledPin, mappedValue);
  volts = mappedValue * 5.00 / 255.00;
  
  String msg = "Tensao: ";
  msg += volts;
  msg += "V/5V";
  
  Serial.println(msg);
}
