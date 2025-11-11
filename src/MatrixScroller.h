// src/MatrixScroller.h
#pragma once
#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

class MatrixScroller {
public:
  explicit MatrixScroller(ArduinoLEDMatrix& m);
  void begin(uint16_t interval_ms = 60);
  void setText(const String& s);          // setzt Text, reset Scroll
  void setSpeed(uint16_t interval_ms);
  void setRepeat(uint32_t times);          // 0 = unendlich, 1 = einmal, 2 = zweimal, ...
  void reset();                            // zurück auf Start
  void update();                           // im loop() aufrufen
  bool isFinished() const;                 // true, wenn Zielanzahl erreicht (times>0)

private:
  ArduinoLEDMatrix& mx;
  uint16_t interval;
  uint32_t lastTick;
  int32_t off;
  String text;

  uint32_t repeatTarget;                   // 0 = unendlich
  uint32_t repeatCount;                    // abgeschlossene Durchläufe
  bool finished;

  static const uint8_t* glyph(char c);
  static void drawWindow(uint8_t frame[8][12], const String& s, int32_t xoff);
};
