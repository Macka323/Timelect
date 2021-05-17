#include <FastLED.h>
#define NUM_LEDS 147
#define DATA_PIN 3
CRGB leds[NUM_LEDS];
int time;
int display[4];
int display_last[4];

  int r = 0, g = 50, b = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop() {

  if (Serial.available() > 0) {
      time = Serial.parseInt();
      for(int i=0;i<NUM_LEDS;i++){
  leds[i].setRGB(0, 0, 0);
  
}FastLED.show();
  }


  display[0] = time / 1000;
  display[1] = time / 100 % 10;
  display[2] = time % 100 / 10;
  display[3] = time % 10;

  Serial.print("display 0 - ");
  Serial.println(display[0]);
  Serial.print("display 1 - ");
  Serial.println(display[1]);
  Serial.print("display 2 - ");
  Serial.println(display[2]);
  Serial.print("display 3 - ");
  Serial.println(display[3]);

if(display_last[0]==display[0]){
  r=0;
  b=0;
  g=0;
}
else{
  g=50;
}
if(display_last[1]==display[1]){
  r=0;
  b=0;
  g=0;
}
else{
  g=50;
}
if(display_last[2]==display[2]){
  r=0;
  b=0;
  g=0;
}
else{
  g=50;
}
if(display_last[3]==display[3]){
  r=0;
  b=0;
  g=0;
}
else{
  g=50;
}

  numb(0, display[0]);
  numb(1, display[1]);
  numb(2, display[2]);
  numb(3, display[3]);

  display_last[0]=display[0];
  display_last[1]=display[1];
  display_last[2]=display[2];
  display_last[3]=display[3];



}


