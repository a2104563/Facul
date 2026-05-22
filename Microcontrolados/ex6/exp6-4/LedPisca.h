#ifndef LEDPISCA_H
#define LEDPISCA_H
#include <Arduino.h>

class LedPisca{
  private:
    int _pino;
    int Estado_led;
    int tPwm;
    volatile int timer_led;
  public:
    LedPisca(int pino);
    void tick(void);
    void timer(void);
};

#endif