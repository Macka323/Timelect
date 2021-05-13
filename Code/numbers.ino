int numb(int display, int number) {


  int r = 0, g = 50, b = 0;
 
  display = 3;

  
   number = 0;

Serial.println("stiga do funkcijata numb");
Serial.println(number);
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

void led1(){
    leds[19 - add].setRGB(r, g, b);
    leds[18 - add].setRGB(r, g, b);
}
void led2(){
    leds[24 + add].setRGB(r, g, b);
    leds[59 - add].setRGB(r, g, b);
}
void led3(){
    leds[108 + add].setRGB(r, g, b);
    leds[101 - add].setRGB(r, g, b);
}
void led4(){
    leds[145 - add].setRGB(r, g, b);
    leds[144 - add].setRGB(r, g, b);
}
void led5(){
    leds[104 - add].setRGB(r, g, b);
    leds[105 + add].setRGB(r, g, b);
}
void led6(){
    leds[21 + add].setRGB(r, g, b);
    leds[62 - add].setRGB(r, g, b);
}
void led7(){
    leds[64 - add].setRGB(r, g, b);
    leds[65 - add].setRGB(r, g, b);
}


  if (number == 0) {

  FastLED.show();
  }

  if (number == 1) {
    
  FastLED.show();
  }

  if (number == 2) {
    
  FastLED.show();
  }

  if (number == 3) {  

  FastLED.show();
  }
  
  if (number == 4) {
      
  FastLED.show();
  }
}
