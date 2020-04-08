#include "AnalogReader.h"

/*
 * @param pin
 *        pin number that a sensor is connected 
 */

AnalogReader::AnalogReader(const uint8_t pin) {
  _pin = pin;
}

/*
 * @return result of the analogRead(pin) function
 */

uint16_t AnalogReader::getValue() {
  return analogRead(_pin);
}

/*
 * @param samples
 *        number of samples
 * @return average value of n-samples
 */

uint16_t AnalogReader::getAverageValue(const uint16_t samples) {
  uint32_t value = 0;
  for (uint16_t x = 0; x < samples; x++) value += analogRead(_pin);
  return value / samples;
}

/*
 * @param min
 *        min value that method can return
 * @param max
 *        max value that method can return
 * @return value that is between min and max
 */

uint16_t AnalogReader::getBetweenValue(const uint16_t min, const uint16_t max) {
  uint16_t value = analogRead(_pin);
  return (value < min) ? min : ((value > max) ? max : value);
}

/*
 * @return middle value of three values (the median function)
 */

uint16_t AnalogReader::getMiddleValue() {
  uint16_t a = analogRead(_pin);
  uint16_t b = analogRead(_pin);
  uint16_t c = analogRead(_pin);
  uint16_t middle;
  if (a <= b && a <= c) middle = b <= c ? b : c;
  else if (b <= a && b <= c) middle = a <= c ? a : c;
  else middle = a <= b ? a : b;
  return middle;
}