#ifndef LEITURAPOT_H
#define LEITURAPOT_H

#include <Arduino.h>

class LeituraPot {
  private:
    int _pino;
    int _intervalo;
    volatile int _timer_pot;

  public:
    LeituraPot(int pino, int intervalo_ms);
    void tick();
    void timer();
};

#endif