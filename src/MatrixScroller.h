// src/MatrixScroller.h
#pragma once
#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

class MatrixScroller {
public:
  explicit MatrixScroller(ArduinoLEDMatrix& m);
  void begin(uint16_t interval_ms = 60);
  void setText(const String& s);
  void setSpeed(uint16_t interval_ms);
  void update();

private:
  ArduinoLEDMatrix& mx;
  uint16_t interval;
  uint32_t lastTick;
  int32_t off;
  String text;

  static const uint8_t* glyph(char c);
  static void drawWindow(uint8_t frame[8][12], const String& s, int32_t xoff);
};
