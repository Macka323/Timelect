#include <FastLED.h>
#define NUM_LEDS 147
#define DATA_PIN 3
CRGB leds[NUM_LEDS];


int x[5],xl[5];
char y;
int r=0,g=0,b=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    y = Serial.read();
    if (y == 'a') {
      x[0] = Serial.read() - 48;
      x[1] = Serial.read() - 48;
      x[2] = Serial.read() - 48;
      x[3] = Serial.read() - 48;
      Serial.print("x1-");
      Serial.println(x[0]);
      Serial.print("x2-");
      Serial.println(x[1]);
      Serial.print("x3-");
      Serial.println(x[2]);
      Serial.print("x4-");
      Serial.println(x[3]);

      if (xl[0] != x[0]) {
        r = 0;
        b = 0;
        g = 0;
      } else {
        g = 50;
      }
      if (xl[1] != x[1]) {
        r = 0;
        b = 0;
        g = 0;
      } else {
        g = 50;
      }
      if (xl[2] != x[2]) {
        r = 0;
        b = 0;
        g = 0;
      } else {
        g = 50;
      }
      if (xl[3] != x[3]) {
        r = 0;
        b = 0;
        g = 0;
      } else {
        g = 50;
      }
    }
    
  numb(0, x[0]);
  numb(1, x[1]);
  numb(2, x[2]);
  numb(3, x[3]);
  xl[0] = x[0];
  xl[1] = x[1];
  xl[2] = x[2];
  xl[3] = x[3];

}
