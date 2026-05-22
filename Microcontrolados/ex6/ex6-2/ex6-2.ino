#include "LedPisca.h"

// Instancia o objeto no pino 13
LedPisca led(13);

void setup() {
  Serial.begin(115200);

  // Configuração do Timer1 (Modo CTC)
  noInterrupts();           // Desabilita interrupções durante config
  TCCR1A = 0;              
  TCCR1B = 0; 
  TCNT1  = 0;

  // OCR1A = (Fosc / (N * Fint)) - 1
  // OCR1A = (16.000.000 / (64 * 1000)) - 1 = 249
  OCR1A = 249;

  // Liga modo CTC e Prescaler de 64
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS11) | (1 << CS10);

  // Habilita interrupção por comparação A
  TIMSK1 |= (1 << OCIE1A);
  interrupts();             // Reabilita interrupções
}

void loop() {
  led.tick(); // Executa a máquina de estados
}

// Vetor de Interrupção do Timer1
ISR(TIMER1_COMPA_vect) {
  led.timer(); // Incrementa os contadores internos da classe a cada 1ms
}