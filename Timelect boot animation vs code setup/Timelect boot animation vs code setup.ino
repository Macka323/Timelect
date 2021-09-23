#include "FastLED.h"

#define NUM_LEDS 147

#define DATA_PIN 15

// Define the array of leds
CRGB leds[NUM_LEDS];

int display[7][21] = {
    {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41},
    {62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42},
    {63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83},
    {104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84},
    {105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125},
    {146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126}};


void setup()
{

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // GRB ordering is assumed
  FastLED.clear();

  int staticImages_cannon_targetBomb[11] = {104, 103, 105, 107, 146, 145, 144, 88, 87, 121, 122};
  for (byte i = 0; i < 7; i++)
  {
    leds[staticImages_cannon_targetBomb[i]].setRGB(0, 10, 0);
  }
  for (byte i = 7; i < 11; i++)
  {
    leds[staticImages_cannon_targetBomb[i]].setRGB(10, 0, 0);
  }
  FastLED.show();
}

void loop()
{
int snake[15] = {106, 102, 66, 58, 26, 56, 70, 96, 114, 94, 74, 50, 34, 48, 78};

  for (int i = 0; i < 20; i++)
  {
    leds[snake[i]].setRGB(0, 10, 10);
    leds[snake[i - 4]].setRGB(0, 0, 0);
    delay(200);
    FastLED.show();
  }
}