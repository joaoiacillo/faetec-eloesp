const int numeros[10][7] = {
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

const int leds[] = { 13, 12, 11, 10, 9, 8, 7 };

int i;
int j;

void setup() {
  for (i = 0; i < 7; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void lightOnNumber(int number) {
  for (j = 0; j < 7; j++) {
   	digitalWrite(leds[j], numeros[number][j]);
  }
}

void loop() {
  for (int i = 0; i < 10; i++) {
  	lightOnNumber(i);
    delay(1000);
  }
}
