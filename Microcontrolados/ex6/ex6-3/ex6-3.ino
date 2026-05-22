#include "LedPisca.h"
#include "LeituraPot.h"

//LEDpino 13
LedPisca led(13);

//potenciometro pino, lendo a cada 200ms
LeituraPot potenciometro(A0, 200);

void setup() {
  Serial.begin(115200);

  //Timer1 CTC 
  noInterrupts();
  TCCR1A = 0;             
  TCCR1B = 0;
  TCNT1  = 0;

  //OCR1A = (16MHz / (64 * 1000Hz)) - 1 = 249
  OCR1A = 249;

  TCCR1B |= (1 << WGM12);               //modo CTC
  TCCR1B |= (1 << CS11) | (1 << CS10);  //prescaler 64

  TIMSK1 |= (1 << OCIE1A);              //interrup
  interrupts();
}

void loop() {
  led.tick();
  potenciometro.tick();
}

//interrupcao de hardware
ISR(TIMER1_COMPA_vect) {
  led.timer();
  potenciometro.timer();
}
