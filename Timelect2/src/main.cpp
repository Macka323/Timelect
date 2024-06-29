#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 147
#define DATA_PIN 25
CRGB leds[NUM_LEDS];

WiFiServer server(80);
String header;

// put function declarations here:
int charsToint(char a, char b, char c)
{
  int num = (a - '0') * 100;
  num += (b - '0') * 10;
  num += c - '0';
  return num;
}

int coordinatesToLed(int x, int y)
{
  int a = 0;
  if (x % 2 == 0)
  {
    a = x * 21 + y;
  }
  else
  {
    a = (x + 1) * 21 - y-1;
  }
  return a;
}

void setup()
{
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_APSTA);

  WiFi.begin("OpenWrt 5G", "modecom32");

  for (int i = 0; i < 5; i++)
  {
    if (WiFi.status() == WL_CONNECTED)
      break;
    Serial.print("Trying to connect ");
    Serial.print(i);
    Serial.print('/');
    Serial.println(5);
    delay(500);
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Goint into AP mode, connect to ESP display, and go to 192.168.4.1");
    WiFi.softAP("ESP display");
    server.begin();
  }
  else
  {
    server.begin();
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  // scan for nearby networks:
  // Serial.println("** Scan Networks **");

  WiFiClient client = server.available();

  if (client)
  {

    //  Serial.println("new client");

    // an http request ends with a blank line

   
    while (client.connected())
    {

      if (client.available())
      {
        String get = client.readStringUntil('\n');
        while (client.available())
          client.read();
        // char c = client.read();

        Serial.println(get);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close"); // the connection will be closed after completion of the response
        // client.println("Refresh: 5"); // refresh the page automatically every 5 sec
        client.println();

        // setPixel/x05y16r000g255b000
        if (get[5] == 's')
        {
          int x = charsToint('0', get[15], get[16]);
          int y = charsToint('0', get[18], get[19]);
          int r = charsToint(get[21], get[22], get[23]);
          int g = charsToint(get[25], get[26], get[27]);
          int b = charsToint(get[29], get[30], get[31]);
          leds[coordinatesToLed(x,y)].setRGB(r, g, b);
          FastLED.show();
        }
        // connect/1234
        if (get[5] == 'c')
        {

          int a = charsToint('0', '0', get[13]);
          a += charsToint('0', '0', get[14]);
          a += charsToint('0', '0', get[15]);
          a += charsToint('0', '0', get[16]);

          client.println(a);
        }
        break;
      }
    }

    // give the web browser time to receive the data

    delay(1);

    // close the connection:

    client.stop();

    // Serial.println("client disconnected");
  }
}
