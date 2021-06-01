#include <FastLED.h>
#define NUM_LEDS 147
#define DATA_PIN 4
CRGB leds[NUM_LEDS];


int x[5], c[9];
char y;

int r=0,g=5,b=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}

void loop() {
  // put your main code here, to run repeatedly:


    for(;;){
      if(Serial.available()>0){
        break;
      }
    }

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

      r=c[0]+c[1]*10+c[2]*100;
      g=c[3]+c[4]*10+c[5]*100;
      b=c[6]+c[7]*10+c[8]*100;
      
      Serial.print("r = ");
      Serial.println(r);
      Serial.print("g = ");
      Serial.println(g);
      Serial.print("b = ");
      Serial.println(b);
      
      
    }

    numb(0, x[0]);
    numb(1, x[1]);
    numb(2, x[2]);
    numb(3, x[3]);

    for (int i=10;i<136;i+=21){
      for(int a=0;a<10;a++){
      leds[i].setRGB(0, 0, 0);
      FastLED.show();
      delay(500);
      leds[i].setRGB(r, g, b);
      FastLED.show();
      delay(500);
      }
    }
  
}
