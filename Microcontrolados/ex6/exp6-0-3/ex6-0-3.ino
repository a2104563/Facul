#define ledPin 13
/*
T = (65536 - TCNT1) × (Prescaler / Fosc)
(T x Fosc) / (Prescaler) =  (65536 - TCNT1)
TCNT1 = 65536 - [(T x Fosc) / (Prescaler)]
------
T=  100ms
Fosc= 16000000 (16Mhz)
Prescaler = 64
-------
TCNT1 = 65536 - [(100 x 16000000) / (64)]
TCNT1 = 40536
TCNT1 = 0x9E58 (decimal)

*/

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  //timer1 interrupção 100ms
  TCCR1A = 0;              
  TCCR1B = 0;

  //prescaler=64: CS11= 1 e CS10= 1
  TCCR1B |= (1 << CS11) | (1 << CS10);

  TCNT1 = 0x9E58;         

  TIMSK1 |= (1 << TOIE1);  //overflow
}

void loop() {

}

//interrupção do timer1
ISR(TIMER1_OVF_vect) {
  TCNT1 = 0x9E58;          //reinicia timer com o valor calculado
  digitalWrite(ledPin, !digitalRead(ledPin)); //pisca led
}
