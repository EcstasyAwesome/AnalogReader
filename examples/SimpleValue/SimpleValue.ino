#include <AnalogReader.h>

AnalogReader sensor(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Value is ");
  Serial.println(sensor.getValue());
  delay(1000);
}
