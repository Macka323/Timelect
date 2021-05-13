int numbers[4][NUM_LEDS];


int numb(int display, int number) {
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
  number=y;

int add;

if (display ==0){
  add=0;
}
if (display ==1){
  add=5;
}
if (display ==2){
  add=12;
}
if (display ==3){
  add=17;
}

  if (number == 0) {
  leds[1+add].setRGB( r, g, b);
  leds[2+add].setRGB( r, g, b);
  leds[21+add].setRGB( r, g, b);
  leds[42+add].setRGB( r, g, b);
  leds[84+add].setRGB( r, g, b);
  leds[105+add].setRGB( r, g, b);
  leds[127+add].setRGB( r, g, b);
  leds[128+add].setRGB( r, g, b);
  leds[108+add].setRGB( r, g, b);
  leds[87+add].setRGB( r, g, b);
  leds[24+add].setRGB( r, g, b);
  leds[45+add].setRGB( r, g, b);
  }
  if (number == 1){
  leds[24+add].setRGB( r, g, b);
  leds[45+add].setRGB( r, g, b);
  leds[87+add].setRGB( r, g, b);
  leds[108+add].setRGB( r, g, b);
  }
  if (number == 2){
    leds[1+add].setRGB( r, g, b);
    leds[2+add].setRGB( r, g, b);
    leds[24+add].setRGB( r, g, b);
    leds[45+add].setRGB( r, g, b);
    leds[65+add].setRGB( r, g, b);
    leds[64+add].setRGB( r, g, b);
    leds[84+add].setRGB( r, g, b);
    leds[105+add].setRGB( r, g, b);
    leds[127+add].setRGB( r, g, b);
    leds[128+add].setRGB( r, g, b);
  }
  if (number==3){
    leds[1+add].setRGB( r, g, b);
    leds[2+add].setRGB( r, g, b);
    leds[24+add].setRGB( r, g, b);
    leds[45+add].setRGB( r, g, b);
    leds[65+add].setRGB( r, g, b);
    leds[64+add].setRGB( r, g, b);
    leds[87+add].setRGB( r, g, b);
    leds[108+add].setRGB( r, g, b);
    leds[127+add].setRGB( r, g, b);
    leds[128+add].setRGB( r, g, b);
  }
  if(number==4){
    
  }

  return y;
}
