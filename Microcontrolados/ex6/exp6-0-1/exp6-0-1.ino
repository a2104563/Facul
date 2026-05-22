#define LED_PIN 13

unsigned long startMicros = 0;
const unsigned long FADE_IN = 300000;  // 300ms em micros
const unsigned long FADE_OUT = 600000; // 600ms acumulados
const unsigned long TOTAL_CYCLE = 1100000; // 1.1s total

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMicros = micros();
  unsigned long elapsed = currentMicros - startMicros;

  if (elapsed < FADE_IN) {
    // Fase 1: Aumentando (0 a 300ms)
    int duty = map(elapsed, 0, FADE_IN, 0, 255);
    analogWrite(LED_PIN, duty);
  } 
  else if (elapsed < FADE_OUT) {
    // Fase 2: Diminuindo (300ms a 600ms)
    int duty = map(elapsed, FADE_IN, FADE_OUT, 255, 0);
    analogWrite(LED_PIN, duty);
  } 
  else if (elapsed < TOTAL_CYCLE) {
    // Fase 3: Apagado (600ms a 1100ms)
    analogWrite(LED_PIN, 0);
  } 
  else {
    // Reinicia o ciclo
    startMicros = currentMicros;
  }
}