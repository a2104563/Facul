#include "LedPisca.h"
#include "LeituraPot.h"
#include "Display7Seg.h"

LedPisca led(13);
LeituraPot potenciometro(A0, 500); // pino(a0, a 500ms)
//pinos 22(a), 23(b), 24(c), 25(d), 26(e), 27(f), 28(g)
Display7Seg display(22, 23, 24, 25, 26, 27, 28);

void setup() {
  Serial.begin(115200);

  //Timer1 Modo CTC 1kHz-1ms
  noInterrupts();
  TCCR1A = 0;              
  TCCR1B = 0; 
  TCNT1  = 0;
  //OCR1A = (16MHz / (64 * 1000Hz)) - 1 = 249
  OCR1A = 249;
  TCCR1B |= (1 << WGM12);               
  TCCR1B |= (1 << CS11) | (1 << CS10);  //prescaler 64
  TIMSK1 |= (1 << OCIE1A);              
  interrupts();
}

void loop() {
  led.tick();
  potenciometro.tick();
  display.tick();
}

ISR(TIMER1_COMPA_vect) {
  led.timer();
  potenciometro.timer();
  display.timer();
}