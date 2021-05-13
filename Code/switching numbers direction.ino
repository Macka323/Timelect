/*int switch(int number){
  int y;

  if (number >= 0 && number <= 20) {
    y = map(number, 20, 0, 0, 20);
  } else if (number >= 42 && number <= 62) {
    y = map(number, 62, 42, 42, 62);
  } else if (number >= 84 && number <= 104) {
    y = map(number, 104, 84, 84, 104);
  } else if (number >= 126 && number <= 146) {
    y = map(number, 146, 126, 126, 146);
  } else {
    y = number;
  }
  return y;
}*/

void led1(int add) {
  leds[19 - add].setRGB(r, g, b);
  leds[18 - add].setRGB(r, g, b);
}
void led2(int add) {
  leds[24 + add].setRGB(r, g, b);
  leds[59 - add].setRGB(r, g, b);
}
void led3(int add) {
  leds[108 + add].setRGB(r, g, b);
  leds[101 - add].setRGB(r, g, b);
}
void led4(int add) {
  leds[145 - add].setRGB(r, g, b);
  leds[144 - add].setRGB(r, g, b);
}
void led5(int add) {
  leds[104 - add].setRGB(r, g, b);
  leds[105 + add].setRGB(r, g, b);
}
void led6(int add) {
  leds[21 + add].setRGB(r, g, b);
  leds[62 - add].setRGB(r, g, b);
}
void led7(int add) {
  leds[64 + add].setRGB(r, g, b);
  leds[65 + add].setRGB(r, g, b);
}