#include <Arduino.h>
#include <WiFi.h>
#include "AsyncUDP.h"
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 147
#define DATA_PIN 25
CRGB leds[NUM_LEDS];

#define MaxClients 5
WiFiClient *clients[5] = {NULL};
#define CommandBufferSize 10
int RequestNumber = 0;

WiFiServer server(80);
AsyncUDP udp;

int coordinatesToLed(int x, int y)
{
  int a = 0;
  if (x % 2 == 0)
  {
    a = x * 21 + y;
  }
  else
  {
    a = (x + 1) * 21 - y - 1;
  }
  return a;
}

struct Point
{
  int x;
  int y;
};

Point LedtoCoordinates(int a)
{
  Point p;
  p.x = ((a - 1) / 21);
  if (p.x % 2 == 0)
  {
    p.y = (a - 1) % 21;
  }
  else
  {
    p.y = 21 - (a - 1) % 21;
  }
  return p;
}

void echoCommand(int originDevice, byte *data, int lenght)
{
  // end command
  data[lenght++] = 255;
  for (int i = 0; i < MaxClients; i++)
  {
    if (clients[i] != NULL && clients[i]->connected())
    {
      if (i != originDevice)
        clients[i]->write(data, lenght);
    }
  }
}

/// @brief
/// @param a
/// @param arr
/// @param offset form where to write the digits
/// @param lenght
void intToByteArr(int a, byte *arr, int offset, int &lenght)
{
  int i = 0;
  while (a / 10 != 0)
  {
    arr[i + offset] = a % 10;
    a = a / 10;
    i++;
  }
  arr[i + offset] = a % 10;
  a = a / 10;
  i++;

  lenght = i;

  // flip
  for (int i = 0; i < lenght / 2; i++)
  {
    int pom = arr[i + offset];
    arr[i + offset] = arr[lenght - i];
    arr[lenght - i] = pom;
  }
}

void SendRequestNumberV1()
{
  for (int i = 0; i < MaxClients; i++)
  {
    if (clients[i] != NULL && clients[i]->connected())
    {
      byte loll[15];
      loll[0] = 'r';
      loll[1] = 'n';
      int lenght=0;
      intToByteArr(RequestNumber,loll,2,lenght);
      loll[lenght+2]=255;
      clients[i]->write(loll,lenght+3);
    }
  }
}
void SendRequestNumberV2()
{
  for (int i = 0; i < MaxClients; i++)
  {
    if (clients[i] != NULL && clients[i]->connected())
    {
      byte * rn = (byte*)&RequestNumber;
      byte loll[15];
      loll[0] = 'r';
      loll[1] = 'n';
      loll[2] = rn[0];
      loll[3] = rn[1];
      loll[4] = rn[2];
      loll[5] = rn[3];
      loll[6] = (byte)255;
      clients[i]->write(loll,7);
    }
  }
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
  }

  server.begin();

  if (udp.listen(45454))
  {

    udp.onPacket([](AsyncUDPPacket packet)
                 {
      if (strcmp("08b8da52", (const char *)packet.data()))
      {
        packet.printf("23010534");
      } });
  }

  // https://www.instructables.com/ESP32-Control-Via-UDP-Datagrams/
}

void loop()
{
  WiFiClient client = server.available();

  if (client)
  {
    // check if its allready connected
    Serial.println("new client");
    bool isConnected = false;
    for (int i = 0; i < MaxClients; i++)
    {
      if (clients[i] != NULL)
      {
        if (client.remoteIP() == clients[i]->remoteIP() && client.remotePort() == clients[i]->remotePort())
          isConnected = true;
      }
    }
    // if its not connect it
    if (!isConnected)
      for (int i = 0; i < MaxClients; i++)
      {
        if (clients[i] == NULL || !clients[i]->connected())
        {
          clients[i] = new WiFiClient(client);
          Serial.println("client added to the array");
          break;
        }
      }
  }
  else
  {
    // delete old disconnected clients
    for (int i = 0; i < MaxClients; i++)
    {
      if (clients[i] != NULL)
      {
        if (!(clients[i]->connected()))
        {
          delete clients[i];
          clients[i] = NULL;
          Serial.println("deleted or client disconnected");
        }
      }
    }
  }

  for (int i = 0; i < MaxClients; i++)
  {
    if (clients[i] != NULL && clients[i]->available())
    {
      byte recived[CommandBufferSize];

      int read = clients[i]->readBytesUntil(255, recived, CommandBufferSize);

      // client.println();
      Serial.write(recived, read);
      Serial.println();

      // setPixel/x05y16r000g255b000
      if (recived[0] == 's' && recived[1] == 'p')
      {
        int x = recived[2]; // charsToint('0', get[15], get[16]);
        int y = recived[3]; // charsToint('0', get[18], get[19]);
        int r = recived[4]; // charsToint(get[21], get[22], get[23]);
        int g = recived[5]; // charsToint(get[25], get[26], get[27]);
        int b = recived[6]; // charsToint(get[29], get[30], get[31]);
        leds[coordinatesToLed(x, y)].setRGB(r, g, b);
        FastLED.show();
        echoCommand(i, recived, read);
        SendRequestNumberV1();
      }
      // co1234
      if (recived[0] == 'c' && recived[1] == 'o')
      {

        int a = recived[2] + recived[3] + recived[4] + recived[5];
        clients[i]->print(a);
        Serial.println(a);
      }
    }
  }
  delay(1);
}
