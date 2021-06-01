#include <Arduino.h>
#include <FastLED.h>
#define NUM_LEDS 147
#define DATA_PIN 4
CRGB leds[NUM_LEDS];


int x[5], c[9];
char y;

void led1(int add,int r,int g, int b) {
  leds[19 - add].setRGB(r, g, b);
  leds[18 - add].setRGB(r, g, b);
}
void led2(int add,int r,int g, int b) {
  leds[24 + add].setRGB(r, g, b);
  leds[59 - add].setRGB(r, g, b);
}
void led3(int add,int r,int g, int b) {
  leds[108 + add].setRGB(r, g, b);
  leds[101 - add].setRGB(r, g, b);
}
void led4(int add,int r,int g, int b) {
  leds[145 - add].setRGB(r, g, b);
  leds[144 - add].setRGB(r, g, b);
}
void led5(int add,int r,int g, int b) {
  leds[104 - add].setRGB(r, g, b);
  leds[105 + add].setRGB(r, g, b);
}
void led6(int add,int r,int g, int b) {
  leds[21 + add].setRGB(r, g, b);
  leds[62 - add].setRGB(r, g, b);
}
void led7(int add,int r,int g, int b) {
  leds[64 + add].setRGB(r, g, b);
  leds[65 + add].setRGB(r, g, b);
}

int numb(int display, int number) {

  int add;

  if (display == 0) {
    add = 0;
  }
  if (display == 1) {
    add = 5;
  }
  if (display == 2) {
    add = 12;
  }
  if (display == 3) {
    add = 17;
  }

int r=0,g=5,b=0;


  if (number == 0) {
    led1(add,r,g,b);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,r,g,b);
    led5(add,r,g,b);
    led6(add,r,g,b);
    led7(add,0,0,0);
  FastLED.show();
  }

  if (number == 1) {
    led1(add,0,0,0);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,0,0,0);
    led5(add,0,0,0);
    led6(add,0,0,0);
    led7(add,0,0,0);
  FastLED.show();
  }

  if (number == 2) {
    led1(add,r,g,b);
    led2(add,r,g,b);
    led3(add,0,0,0);
    led4(add,r,g,b);
    led5(add,r,g,b);
    led6(add,0,0,0);
    led7(add,r,g,b);
  FastLED.show();
  }

  if (number == 3) {
    led1(add,r,g,b);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,r,g,b);
    led5(add,0,0,0);
    led6(add,0,0,0);
    led7(add,r,g,b);
  FastLED.show();
  }

  if (number == 4) {
    led1(add,0,0,0);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,0,0,0);
    led5(add,0,0,0);
    led6(add,r,g,b);
    led7(add,r,g,b);
    
  FastLED.show();
  }
  if(number==5){
    led1(add,r,g,b);
    led2(add,0,0,0);
    led3(add,r,g,b);
    led4(add,r,g,b);
    led5(add,0,0,0);
    led6(add,r,g,b);
    led7(add,r,g,b);
    
FastLED.show();
  }
  if (number==6){
    led1(add,r,g,b);
    led2(add,0,0,0);
    led3(add,r,g,b);
    led4(add,r,g,b);
    led5(add,r,g,b);
    led6(add,r,g,b);
    led7(add,r,g,b);
    FastLED.show();
  }
  if(number==7){
    led1(add,r,g,b);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,0,0,0);
    led5(add,0,0,0);
    led6(add,0,0,0);
    led7(add,0,0,0);
    FastLED.show();
  }
  if (number==8){
    led1(add,r,g,b);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,r,g,b);
    led5(add,r,g,b);
    led6(add,r,g,b);
    led7(add,r,g,b);
    FastLED.show();
  }
  if (number==9){
    led1(add,r,g,b);
    led2(add,r,g,b);
    led3(add,r,g,b);
    led4(add,r,g,b);
    led5(add,0,0,0);
    led6(add,r,g,b);
    led7(add,r,g,b);
    FastLED.show();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:


    if (Serial.read() == 'a') {
      
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
    }
   
    if (Serial.read() == 'c') {
      
      c[0] = Serial.read() - 48;
      c[1] = Serial.read() - 48;
      c[2] = Serial.read() - 48;
      c[3] = Serial.read() - 48;
      c[4] = Serial.read() - 48;
      c[5] = Serial.read() - 48;
      c[6] = Serial.read() - 48;
      c[7] = Serial.read() - 48;
      c[8] = Serial.read() - 48;
    }

    

    numb(0, x[0]);
    numb(1, x[1]);
    numb(2, x[2]);
    numb(3, x[3]);
  
}