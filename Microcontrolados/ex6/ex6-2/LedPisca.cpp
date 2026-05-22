#include "LedPisca.h"

LedPisca::LedPisca(int pino) {
  _pino = pino;
  pinMode(_pino, OUTPUT);
  Estado_led = 1;
  tPwm = 0;
  timer_led = 0;
}

void LedPisca::tick() {
  switch (Estado_led) {
    case 1: //brilho aumenta e diminui
      if (tPwm < 300) {
        // 0 a 300ms aumenta (0 a 255)
        analogWrite(_pino, map(tPwm, 0, 300, 0, 255));
      } 
      else if (tPwm < 600) {
        // 301 a 600ms diminui 255 a 0
        analogWrite(_pino, map(tPwm, 300, 600, 255, 0));
      }

      //contador tPwm  incrementado por timer() a cada 1ms
      if (tPwm >= 600) {
        analogWrite(_pino, 0); //apaga led
        tPwm = 0;
        timer_led = 500;       //pausa
        Estado_led = 2;        //proximo estado
      }
      break;

    case 2: //apagado
      if (timer_led == 0) {
        Estado_led = 1;        //reinicia (volta estado1)
      }
      break;
  }
}

void LedPisca::timer() {
  // Esta função deve ser chamada dentro da ISR a cada 1ms
  if (Estado_led == 1) {
    tPwm++; 
  }
  if (timer_led > 0) {
    timer_led--;
  }
}