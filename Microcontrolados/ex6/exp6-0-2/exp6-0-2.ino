#define LED_PIN 13

// Variáveis para o LED (Exercício 6.0.1)
unsigned long startMicros = 0;

// Variáveis para o Cronômetro Serial
unsigned long lastSerialMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();

  // --- Lógica do LED (micros) ---
  unsigned long elapsedLED = currentMicros - startMicros;
  if (elapsedLED < 300000) {
    analogWrite(LED_PIN, map(elapsedLED, 0, 300000, 0, 255));
  } else if (elapsedLED < 600000) {
    analogWrite(LED_PIN, map(elapsedLED, 300000, 600000, 255, 0));
  } else if (elapsedLED < 1100000) {
    analogWrite(LED_PIN, 0);
  } else {
    startMicros = currentMicros;
  }

  // --- Lógica do Cronômetro Serial (millis) ---
  if (currentMillis - lastSerialMillis >= 1000) {
    lastSerialMillis = currentMillis;

    unsigned long totalSegundos = currentMillis / 1000;
    int minutos = totalSegundos / 60;
    int segundos = totalSegundos % 60;

    Serial.print("Tempo de Execucao: ");
    if (minutos < 10) Serial.print("0");
    Serial.print(minutos);
    Serial.print(":");
    if (segundos < 10) Serial.print("0");
    Serial.println(segundos);
  }
}