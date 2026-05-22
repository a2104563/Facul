#define ledPin 13
int count = 0;

/* calculos
fint= Fosc / N*(1+OCR1A)
OCR1A = (Fosc/(N*fint)) - 1
----
Fosc = 16000000 Hz
fint = 1000 Hz
prescaler (N) = 64
----
OCR1A = (16000000/(64*1000)) - 1
OCR1A = 249

*/


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  //Timer1 modo CTC
  TCCR1A = 0; 
  TCCR1B = 0; 
  TCNT1  = 0;         

  //valor de comparacao 1ms= 249
  OCR1A = 249;

  //modo CTC WGM12= 1
  TCCR1B |= (1 << WGM12);

  //prescaler= 64 CS11= 1 e CS10= 1
  TCCR1B |= (1 << CS11) | (1 << CS10); 

  //interrupcao por comparacao (Compare Match A)
  TIMSK1 |= (1 << OCIE1A);
}

void loop() {
  if (count >= 1000) { //1000 interrupções = 1s
    count = 0;
    digitalWrite(ledPin, !digitalRead(ledPin));
    Serial.println("Passou 1 segundo");
  }
}

// Rotina interrupcao
ISR(TIMER1_COMPA_vect) {
  //TCNT1 zera sozinho
  count++;
}
