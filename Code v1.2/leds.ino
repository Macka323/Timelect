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