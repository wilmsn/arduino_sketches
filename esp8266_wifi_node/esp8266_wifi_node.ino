/* Diese Sketch verbindet sich mit dem WLAN, ruft die Seite /test.php auf 
 * und schläft danach wieder für 10 (echte 15) Sekunden.
 * Wichtig: Brücke zwischen RST und GPIO16 nicht vergessen!!!!!!
 * WiFi settings ausgelagert in die Datei: wifisettings.h, muss separat erstellt werden! 
content:
const char* ssid = "wifi-name";
const char* password = "wifi-password";
*/

#include <ESP8266WiFi.h>
#include "wifisettings.h"

// Time to sleep (in seconds):
const int sleepTimeS = 300;   // 5 Minuten

// Host
const char* host = "rpi2.fritz.box";

void setup() 
{

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)) {
    return;
  }
  
  // This will send the request to the server
  client.print(String("GET /test.php")+"\n");
  delay(10);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
  }
  ESP.deepSleep(sleepTimeS * 1000000);
}

void loop() 
{

}

