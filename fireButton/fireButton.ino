#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "realme 8"
#define WIFI_PASSWORD "7777777s"

#define FIREBASE_HOST "https://iotx0-f34a3-default-rtdb.firebaseio.com/"
#define FIREBASE_PATH "/light.json"

void setup() { 
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(String(FIREBASE_HOST) + FIREBASE_PATH);

    int httpCode = http.GET(); // Make GET request

    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      int lightStatus = payload.toInt(); // Convert "0" or "1" to int

      digitalWrite(2, lightStatus);
      Serial.print("Light status: ");
      Serial.println(lightStatus);
    } else {
      Serial.print("GET failed, error: ");
      Serial.println(http.errorToString(httpCode));
    }

    http.end();
  }

  delay(1000);
}
