#include <WiFi.h>
#include <WebServer.h>

// AP credentials
const char* ssid = "ESP_32_server";  // Your AP name
const char* password = "deepanshi"; // Your AP password

WebServer server(80);

// HTML and CSS content
const char index_html[] PROGMEM = R"rawliteral(YOUR_WEB_SESIGN)rawliteral";

const char details_html[] PROGMEM = R"rawliteral(YOUR_HTML_CODE)rawliteral";

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleDetails() {
  server.send(200, "text/html", details_html);
}

void setup() {
  Serial.begin(115200);
  
  // Create Access Point
  Serial.println("Creating Access Point...");
  WiFi.softAP(ssid, password);

  Serial.print("AP SSID: ");
  Serial.println(ssid);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Set up routes
  server.on("/", handleRoot);
  server.on("/details/data", handleDetails);
  
  server.begin();
}

void loop() {
  server.handleClient();
}
