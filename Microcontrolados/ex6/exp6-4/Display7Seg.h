#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

#include <Arduino.h>

class Display7Seg {
  private:
    int _pinos[7];         // a, b, c, d, e, f, g
    int _segundos;
    volatile int _timer_display;
    void mostrarDigito(int num);

  public:
    Display7Seg(int pA, int pB, int pC, int pD, int pE, int pF, int pG);
    void tick();
    void timer();
};

#endif