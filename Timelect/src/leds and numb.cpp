#include <leds and numb.h>
#include <Arduino.h>
#include <FastLED.h>

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

void numb(int display, int number) {

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
