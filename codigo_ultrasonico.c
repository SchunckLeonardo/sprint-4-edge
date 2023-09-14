#include <ArduinoJson.h>

#define echo 11
#define trig 10
#define ledPin 7

unsigned long tempo;
double distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(trig, LOW);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  tempo = pulseIn(echo, HIGH);

  distancia = tempo/58;

  StaticJsonDocument<100> json; // Tamanho do buffer para o JSON

   if (distancia > 400) 
  {
    json["distance"] = distancia;
    json["led"] = 0;
    digitalWrite(ledPin, LOW);
  } 
  else if (distancia < 50) 
  {
    json["distance"] = distancia;
    json["led"] = 1;
    digitalWrite(ledPin, HIGH);
  } 
  else 
  {
    json["distance"] = distancia;
    json["led"] = 0;
    digitalWrite(ledPin, LOW);
  }

  String jsonString;
  serializeJson(json, jsonString);
  
  Serial.println(jsonString); // Envia o JSON via serial

  delay(2500);
}
