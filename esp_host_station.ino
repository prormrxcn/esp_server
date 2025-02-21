#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "your_ssid";
const char* password = "your_password";

WebServer server(80);

// HTML and CSS content
const char index_html[] PROGMEM = R"rawliteral(design_html_code)rawliteral";

const char details_html[] PROGMEM = R"rawliteral(Your_html_program)rawliteral";

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleDetails() {
  server.send(200, "text/html", details_html);
}

void setup() {
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to WiFi. IP address: ");
  Serial.println(WiFi.localIP());

  // Set up routes
  server.on("/", handleRoot);
  server.on("/details/data", handleDetails);
  
  server.begin();
}

void loop() {
  server.handleClient();
}
