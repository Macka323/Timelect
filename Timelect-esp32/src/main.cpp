#include <Arduino.h>
#include <Preferences.h>
#include <WiFi.h>
#include "FastLED.h"

#define NUM_LEDS 147

CRGB leds[NUM_LEDS];

Preferences preferences;

// Replace with your network credentials
char *ssid = NULL;
char *password = NULL;

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";

// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

bool ChangeWIFISettings()
{
  while (Serial.available() > 0)
  {
    char in = Serial.read();

    Serial.println(in);
    if (in == 'W')
    {

      // Serial.read();
      String lssid = Serial.readStringUntil(';');
      Serial.print(lssid);
      if (strcmp(lssid.c_str(), ssid) != 0)
      {
        preferences.putString("ssid", lssid.c_str());
      }
    }
    if (in == 'P')
    {

      // Serial.read();
      String lpass = Serial.readStringUntil(';');

      Serial.print(lpass);
      if (strcmp(lpass.c_str(), password) != 0)
      {
        preferences.putString("password", lpass);
        preferences.end();
        ESP.restart();
      }
      return true;
    }
  }
  return false;
}

void setup()
{

  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);

  preferences.begin("credentials", false);

  String Sssid = preferences.getString("ssid", "defssid");
  String Spass = preferences.getString("password", "defpassssss");
  ssid = (char *)&Sssid;
  password = (char *)&Spass;

  // Connect to Wi-Fi network with SSID and password
  Serial.println("Connecting to ");
  Serial.println(ssid);
  Serial.println(password);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    if (Serial.available() > 0)
    {
      ChangeWIFISettings();
    }
    else
    {
      delay(500);
    }
  }
  // Print local IP address and start web server
  Serial.println("WiFi connected.");
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());
  server.begin();

  FastLED.addLeds<NEOPIXEL, 13>(leds, NUM_LEDS);
  preferences.end();
}

void loop()
{
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client)
  { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    { // loop while the client's connected
      currentTime = millis();
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
        header += c;
        if (c == '\n')
        { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            int charNumber = 14;
            //
            // p001r255g255b255
            // p102r000g255b255

            int QueryStartIndex = header.indexOf("GET /setPixel/") + 14;
            int pin, r, g, b;
            pin = (header[QueryStartIndex + 1] - 48) * 100;
            pin += (header[QueryStartIndex + 2] - 48) * 10;
            pin += header[QueryStartIndex + 3] - 48;

            r = (header[QueryStartIndex + 5] - 48) * 100;
            r += (header[QueryStartIndex + 6] - 48) * 10;
            r += header[QueryStartIndex + 7] - 48;

            g = (header[QueryStartIndex + 9] - 48) * 100;
            g += (header[QueryStartIndex + 10] - 48) * 10;
            g += header[QueryStartIndex + 11] - 48;

            b = (header[QueryStartIndex + 13] - 48) * 100;
            b += (header[QueryStartIndex + 14] - 48) * 10;
            b += header[QueryStartIndex + 15] - 48;

            leds[pin].setRGB(r, g, b);
            FastLED.show();

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.print(".button { background-color: rgb(");
            client.print(r);
            client.print(",");
            client.print(g);
            client.print(",");
            client.print(b);

            client.println("); border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println(pin);

            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button
            if (output26State == "off")
            {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output27State == "off")
            {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          }
          else
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}