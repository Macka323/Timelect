#include <FastLED.h>
#define NUM_LEDS 147
#define DATA_PIN 3
CRGB leds[NUM_LEDS];
int time;
int display[4];
int r=0,g=50,b=0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop() {

  if (Serial.available() > 0) {

    time = Serial.parseInt();
  }
 

  display[0]= time /1000;
  display[1]= time /100%10;
  display[2]= time %100/10;
  display[3]= time %10;

Serial.print("display 0 - ");
Serial.println(display[0]);
Serial.print("display 1 - ");
Serial.println(display[1]);
Serial.print("display 2 - ");
Serial.println(display[2]);
Serial.print("display 3 - ");
Serial.println(display[3]);

if(display[0]=0){
  leds[numb(1)].setRGB( r, g, b);
  leds[numb(2)].setRGB( r, g, b);
  leds[numb(21)].setRGB( r, g, b);
  leds[numb(42)].setRGB( r, g, b);
  leds[numb(84)].setRGB( r, g, b);
  leds[numb(105)].setRGB( r, g, b);
  leds[numb(127)].setRGB( r, g, b);
  leds[numb(128)].setRGB( r, g, b);
  leds[numb(108)].setRGB( r, g, b);
  leds[numb(87)].setRGB( r, g, b);
  leds[numb(24)].setRGB( r, g, b);
  leds[numb(45)].setRGB( r, g, b);
}
if(display[0]=1){
  leds[numb(24)].setRGB( r, g, b);
  leds[numb(45)].setRGB( r, g, b);
  leds[numb(87)].setRGB( r, g, b);
  leds[numb(108)].setRGB( r, g, b);
}else{
  for(int i=0;i<NUM_LEDS;i++){
    leds[i].setRGB( 0, 0, 0);
  }
}


FastLED.show();
}


