#include "Display7Seg.h"

const byte mapa[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

Display7Seg::Display7Seg(int pA, int pB, int pC, int pD, int pE, int pF, int pG) {
  _pinos[0] = pA; _pinos[1] = pB; _pinos[2] = pC; 
  _pinos[3] = pD; _pinos[4] = pE; _pinos[5] = pF; _pinos[6] = pG;

  for(int i = 0; i < 7; i++) {
    pinMode(_pinos[i], OUTPUT);
  }
  _segundos = 0;
  _timer_display = 1000; //inicio com 1 segundo
}

void Display7Seg::mostrarDigito(int num) {
  for(int i = 0; i < 7; i++) {
    digitalWrite(_pinos[i], mapa[num][i]);
  }
}

void Display7Seg::tick() {
  mostrarDigito(_segundos);
  
  if (_timer_display == 0) {
    _segundos++;
    if (_segundos > 9) _segundos = 0; //zera
    _timer_display = 1000;           //reinicia contador 1s
  }
}

void Display7Seg::timer() {
  if (_timer_display > 0) _timer_display--;
}