#include <ESPAsyncWebServer.h>
#include <WiFi.h>

const char *ssid = "Bhatti Hostel(1F)2.4GHz";
const char *password = "123456677";

AsyncWebServer server(80);

void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/page1", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/page1.html", "text/html");
  });

  server.on("/page2", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/page2.html", "text/html");
  });

  server.begin();
}

void loop() {
  // your loop code here
}
