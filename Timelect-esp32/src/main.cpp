#include <Arduino.h>
#include <FastLED.h>



#define DATA_PIN 4
#define NUM_LEDS 147
CRGB leds[NUM_LEDS];


//int r = 0, g = 5, b = 0;

int x[5], c[9];
char y;


class Display
{

public:
    
    int r = 0, g = 5, b = 0;
   void led1(int add, int r, int g, int b);
   void led2(int add, int r, int g, int b);
   void led3(int add, int r, int g, int b);
   void led4(int add, int r, int g, int b);
   void led5(int add, int r, int g, int b);
   void led6(int add, int r, int g, int b);
   void led7(int add, int r, int g, int b);
   void numb(int display, int number);
    
};



void Display::led1(int add, int r, int g, int b)
{
  leds[19 - add].setRGB(r, g, b);
  leds[18 - add].setRGB(r, g, b);
}
void Display::led2(int add, int r, int g, int b)
{
  leds[24 + add].setRGB(r, g, b);
  leds[59 - add].setRGB(r, g, b);
}
void Display::led3(int add, int r, int g, int b)
{
  leds[108 + add].setRGB(r, g, b);
  leds[101 - add].setRGB(r, g, b);
}
void Display::led4(int add, int r, int g, int b)
{
  leds[145 - add].setRGB(r, g, b);
  leds[144 - add].setRGB(r, g, b);
}
void Display::led5(int add, int r, int g, int b)
{
  leds[104 - add].setRGB(r, g, b);
  leds[105 + add].setRGB(r, g, b);
}
void Display::led6(int add, int r, int g, int b)
{
  leds[21 + add].setRGB(r, g, b);
  leds[62 - add].setRGB(r, g, b);
}
void Display::led7(int add, int r, int g, int b)
{
  leds[64 + add].setRGB(r, g, b);
  leds[65 + add].setRGB(r, g, b);
}

void Display::numb(int display, int number)
{

  int add;

  /*if (display == 0)
  {
    add = 0;
  }
  if (display == 1)
  {
    add = 5;
  }
  if (display == 2)
  {
    add = 12;
  }
  if (display == 3)
  {
    add = 17;
  }*/

  switch (display)
  {
  case 0:
    add = 0;
    break;
  case 1:
    add = 5;
    break;
  case 2:
    add = 12;
    break;
  case 3:
    add = 17;
    break;
  }

  //int r=0,g=5,b=0;
  switch (number)
  {
  case 0:
    led1(add, r, g, b);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, r, g, b);
    led5(add, r, g, b);
    led6(add, r, g, b);
    led7(add, 0, 0, 0);
    FastLED.show();
    break;

  case 1:
    led1(add, 0, 0, 0);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, 0, 0, 0);
    led5(add, 0, 0, 0);
    led6(add, 0, 0, 0);
    led7(add, 0, 0, 0);
    FastLED.show();
 break;
  case 2:
    led1(add, r, g, b);
    led2(add, r, g, b);
    led3(add, 0, 0, 0);
    led4(add, r, g, b);
    led5(add, r, g, b);
    led6(add, 0, 0, 0);
    led7(add, r, g, b);
    FastLED.show();
    break;

  case 3:
    led1(add, r, g, b);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, r, g, b);
    led5(add, 0, 0, 0);
    led6(add, 0, 0, 0);
    led7(add, r, g, b);
    FastLED.show();
    break;

  case 4:
    led1(add, 0, 0, 0);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, 0, 0, 0);
    led5(add, 0, 0, 0);
    led6(add, r, g, b);
    led7(add, r, g, b);

    FastLED.show();
    break;
  case 5:
    led1(add, r, g, b);
    led2(add, 0, 0, 0);
    led3(add, r, g, b);
    led4(add, r, g, b);
    led5(add, 0, 0, 0);
    led6(add, r, g, b);
    led7(add, r, g, b);

    FastLED.show();
    break;
  case 6:
    led1(add, r, g, b);
    led2(add, 0, 0, 0);
    led3(add, r, g, b);
    led4(add, r, g, b);
    led5(add, r, g, b);
    led6(add, r, g, b);
    led7(add, r, g, b);
    FastLED.show();
    break;

  case 7:
    led1(add, r, g, b);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, 0, 0, 0);
    led5(add, 0, 0, 0);
    led6(add, 0, 0, 0);
    led7(add, 0, 0, 0);
    FastLED.show();
    break;
  case 8:
    led1(add, r, g, b);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, r, g, b);
    led5(add, r, g, b);
    led6(add, r, g, b);
    led7(add, r, g, b);
    FastLED.show();
    break;
  case 9:
    led1(add, r, g, b);
    led2(add, r, g, b);
    led3(add, r, g, b);
    led4(add, r, g, b);
    led5(add, 0, 0, 0);
    led6(add, r, g, b);
    led7(add, r, g, b);
    FastLED.show();
    break;
  default:
    Serial.println("invalid number");
    for (int i = 0; i < 21; i++)
    {
      leds[i].setRGB(255, 0, 0);
      FastLED.show();
    }
    break;
  }
}


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
}

void loop()
{
    // put your main code here, to run repeatedly:
  Display Displayit;


  
  if (Serial.read() == 'a')
  {
    delay(10);
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
  
  if (Serial.read() == 'c')
  {
    delay(10);
    c[0] = Serial.read() - 48;
    c[1] = Serial.read() - 48;
    c[2] = Serial.read() - 48;
    c[3] = Serial.read() - 48;
    c[4] = Serial.read() - 48;
    c[5] = Serial.read() - 48;
    c[6] = Serial.read() - 48;
    c[7] = Serial.read() - 48;
    c[8] = Serial.read() - 48;

    Displayit.r = c[0] + c[1] * 10 + c[2] * 100;
    Displayit.g = c[3] + c[4] * 10 + c[5] * 100;
    Displayit.b = c[6] + c[7] * 10 + c[8] * 100;

    Serial.print("r = ");
    Serial.println(Displayit.r);
    Serial.print("g = ");
    Serial.println(Displayit.g);
    Serial.print("b = ");
    Serial.println(Displayit.b);
  }

 // x[0] = 5;
 // x[1] = 5;
 // x[2] = 5;
 // x[3] = 5;

  Displayit.numb(0, x[0]);
  Displayit.numb(1, x[1]);
  Displayit.numb(2, x[2]);
  Displayit.numb(3, x[3]);

  /*for (int i = 10; i < 136; i += 21)
  {
    for (int a = 0; a < 10; a++)
    {
      leds[i].setRGB(0, 0, 0);
      FastLED.show();
      delay(500);
      leds[i].setRGB(Displayit.r, Displayit.g, Displayit.b);
      FastLED.show();
      delay(500);
    }
  }*/
   
}
