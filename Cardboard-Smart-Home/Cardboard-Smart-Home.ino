#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

#define PIR_PIN 18

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  pinMode(PIR_PIN, INPUT);

  Serial.println("System uruchomiony");
}

void loop() {

  // ===== DHT22 =====
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {

    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Wilgotnosc: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
  else {
    Serial.println("Blad odczytu DHT22");
  }

  // ===== PIR =====
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("Wykryto ruch!");
  }
  else {
    Serial.println("Brak ruchu");
  }

  Serial.println("----------------");

  delay(2000);
}