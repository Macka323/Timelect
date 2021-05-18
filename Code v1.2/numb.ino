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

  if (number == 0) {
    led1(add);
    led2(add);
    led3(add);
    led4(add);
    led5(add);
    led6(add);
  FastLED.show();
  }

  if (number == 1) {
    led2(add);
    led3(add);
  FastLED.show();
  }

  if (number == 2) {
    led1(add);
    led2(add);
    led7(add);
    led5(add);
    led4(add);
  FastLED.show();
  }

  if (number == 3) {
    led1(add);
    led2(add);
    led7(add);
    led3(add);
    led4(add);
  FastLED.show();
  }

  if (number == 4) {
    led6(add);
    led7(add);
    led2(add);
    led3(add);
  FastLED.show();
  }
  if(number==5){
    led1(add);
    led6(add);
    led7(add);
    led3(add);
    led4(add);
FastLED.show();
  }
  if (number==6){
    led1(add);
    led7(add);
    led3(add);
    led4(add);
    led5(add);
    led6(add);
    FastLED.show();
  }
  if(number==7){
    led1(add);
    led2(add);
    led3(add);
    FastLED.show();
  }
  if (number==8){
    led1(add);
    led2(add);
    led3(add);
    led4(add);
    led5(add);
    led6(add);
    led7(add);
    FastLED.show();
  }
  if (number==9){
    led1(add);
    led2(add);
    led3(add);
    led4(add);
    led6(add);
    led7(add);
    FastLED.show();
  }
}