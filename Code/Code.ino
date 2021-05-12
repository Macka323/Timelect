#include <FastLED.h>
#define NUM_LEDS 147
#define DATA_PIN 3
CRGB leds[NUM_LEDS];
int time;
int display[4];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop() {

  if (Serial.available() > 0) {

    time = Serial.parseInt();
  }

  int number, y;

  number = time;
  if (number >= 0 && number <= 20) {
    y = map(number, 20, 0, 0, 20);
  }
  else if (number >= 42 && number <= 62) {
    y = map(number, 62, 42, 42, 62);
  }
  else if (number >= 84 && number <= 104) {
    y = map(number, 104, 84, 84, 104);
  }
  else if (number >= 126 && number <= 146) {
    y = map(number, 146, 126, 126, 146);
  }else{
    y=number;
  }

  Serial.println(time);
  Serial.println(y);

  delay(700);

  

  display[0]= time /1000;
  display[1]= time /100%10;
  display[2]= time %100/10;
  display[3]= time %10;

/*Serial.print("display 0 - ");
Serial.println(display[0]);
Serial.print("display 1 - ");
Serial.println(display[1]);
Serial.print("display 2 - ");
Serial.println(display[2]);
Serial.print("display 3 - ");
Serial.println(display[3]);*/



}
