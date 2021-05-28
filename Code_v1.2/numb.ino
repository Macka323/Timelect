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

int r=0,g=50,b=0;


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