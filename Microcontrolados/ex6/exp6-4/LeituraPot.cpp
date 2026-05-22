#include "LeituraPot.h"

LeituraPot::LeituraPot(int pino, int intervalo_ms) {
  _pino = pino;
  _intervalo = intervalo_ms;
  _timer_pot = _intervalo;
}

void LeituraPot::tick() {
  if (_timer_pot == 0) {
    int valor = analogRead(_pino);
    Serial.print("Potenciometro (Pino ");
    Serial.print(_pino);
    Serial.print("): ");
    Serial.println(valor);

    _timer_pot = _intervalo; //reinicia tempo leitura
  }
}

void LeituraPot::timer() {
  if (_timer_pot > 0) _timer_pot--;
}