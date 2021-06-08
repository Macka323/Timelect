#include "FastLED.h"

class display
{
private:
    #define NUM_LEDS 147
    CRGB leds[NUM_LEDS];
    
public:
int r=0,g=5,b=0;
void led1(int add,int r,int g, int b);
void led2(int add,int r,int g, int b);
void led3(int add,int r,int g, int b);
void led4(int add,int r,int g, int b);
void led5(int add,int r,int g, int b);
void led6(int add,int r,int g, int b);
void led7(int add,int r,int g, int b);
void numb(int display, int number);
};


