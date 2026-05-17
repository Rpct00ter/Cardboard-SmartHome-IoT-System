#include "DHT.h"

// ===== DHT22 =====
#define DHTPIN 4
#define DHTTYPE DHT22

// ===== PIR =====
#define PIR_PIN 18

// ===== MQ-2 =====
#define GAS_PIN 23

// ==== Czujnik Światła ====
#define LIGHT_PIN 19

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);

  // DHT22
  dht.begin();

  // PIR
  pinMode(PIR_PIN, INPUT);

  // MQ-2
  pinMode(GAS_PIN, INPUT);

  Serial.println("System uruchomiony");
}

void loop() {

  // =========================
  // DHT22
  // =========================

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {

    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Wilgotnosc: ");
    Serial.print(humidity);
    Serial.println(" %");

  } else {

    Serial.println("Blad odczytu DHT22");
  }

  // =========================
  // PIR
  // =========================

  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {

    Serial.println("Wykryto ruch!");

  } else {

    Serial.println("Brak ruchu");
  }

  // =========================
  // MQ-2
  // =========================

  int gasState = digitalRead(GAS_PIN);


  if (gasState == HIGH) {

    Serial.println("Wykryto szkodliwy gaz!");

  } else {

    Serial.println("Powietrze bezpieczne do oddychania");
  }

  // =========================
  // Czujnik światła
  // =========================
  int lightValue = digitalRead(LIGHT_PIN);

  Serial.print("Poziom swiatla: ");
  Serial.println(lightValue);
  int lightState = digitalRead(LIGHT_PIN);

  if (lightState == HIGH) {

    Serial.println("Jest jasno");

  } else {

    Serial.println("Jest ciemno");
  }
  Serial.println("----------------");

  delay(2000);
}
