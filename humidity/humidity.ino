#include <Adafruit_Sensor.h>
#include<DHT.h>
#include<DHT_U.h>

#define DHTPIN 4
#define DHTTYPE DHT1 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float humidity=dht.readHumidity();
  float temperature=dht.readTemperature();

  if(isnan(humidity) || isnan(temperature)){
    Serial.println("Failed to read");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print("temperature: ");
  Serial.print(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}
