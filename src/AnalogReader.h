#ifndef AnalogReader_h
#define AnalogReader_h
#include <Arduino.h>

class AnalogReader {
  private:
    uint8_t _pin;
  public:
    AnalogReader(const uint8_t pin);
    uint16_t getValue();
    uint16_t getMiddleValue();
    uint16_t getAverageValue(const uint16_t samples);
    uint16_t getBetweenValue(const uint16_t min, const uint16_t max);
};

#endif