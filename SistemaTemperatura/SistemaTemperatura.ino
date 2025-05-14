#include <DHT.h>

#define DHTPIN 2          // Pin donde está conectado el sensor DHT22
#define DHTTYPE DHT22     // Tipo de sensor
#define FAN_PIN 9         // Pin para el ventilador

DHT dht(DHTPIN, DHTTYPE);

float threshold = 30.0;   // Umbral de temperatura en °C

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW); // Ventilador apagado inicialmente
}

void loop() {
  delay(5000); // Esperar 5 segundos entre lecturas
  float temp = dht.readTemperature(); // Leer temperatura

  if (isnan(temp)) {
    Serial.println("Error al leer el sensor DHT22");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  // Toma de decisiones automatizada
  if (temp > threshold) {
    digitalWrite(FAN_PIN, HIGH); // Encender ventilador
    Serial.println("Ventilador ENCENDIDO");
  } else {
    digitalWrite(FAN_PIN, LOW);  // Apagar ventilador
    Serial.println("Ventilador APAGADO");
  }
}
