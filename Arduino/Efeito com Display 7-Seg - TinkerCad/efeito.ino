/*** Variables and Constants ***/

//                   A   B   C   D   E  F  G  DP
//                   0   1   2   3   4  5  6  7
const int leds[] = { 13, 12, 11, 10, 9, 8, 7, 6 };


/*** Effects ***/

const int effect1[] = { 0, 1, 6, 5 };

const int effect2[] = { 0, 1, 2, 3, 4, 5 };

const int effect3[] = { 7 };


/*** Indexes ***/

int i;
int r;


/*** Configuration ***/

void setup() {
  for (i = 0; i < 8; i++) pinMode(leds[i], OUTPUT);
}


/*** Functions ***/

void playEffect1() {
    for (r = 0; r < 3; r++) {
        for (i = 0; i < 4; i++) {
            digitalWrite(leds[effect1[i]], HIGH);
            delay(200);
            digitalWrite(leds[effect1[i]], LOW);
        }
    }
}

void playEffect2() {
    for (r = 0; r < 3; r++) {
        for (i = 0; i < 6; i++) {
            digitalWrite(leds[effect2[i]], HIGH);
            delay(200);
            digitalWrite(leds[effect2[i]], LOW);
        }
    }
}

void playEffect3() {
    for (r = 0; r < 5; r++) {
        digitalWrite(leds[effect3[0]], HIGH);
        delay(100);
        digitalWrite(leds[effect3[0]], LOW);
        delay(300);
    }
}


/*** Program ***/

void loop() {
    playEffect1();
    playEffect2();    
    playEffect3();
}
