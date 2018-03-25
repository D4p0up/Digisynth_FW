/* DIGISYNTH Firmware
*/

#include <SPI.h>
#include "digisynth.h"

unsigned char cycle;

void setup() {
  // init SPI
  SPI.begin();
  pinMode(SLATCH, OUTPUT);
  // initialize the digital pin as an output.
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(D11, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
  pinMode(SW6, INPUT);          
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
digitalWrite(SLATCH, HIGH);
SPI.transfer(128);
digitalWrite(SLATCH, LOW);
//test_led_loop(100);
test_button();
}


void test_led_loop(unsigned int tdelay) {
  digitalWrite(D9, HIGH);   
  delay(tdelay);                 
  digitalWrite(D9, LOW);
  delay(tdelay);
  digitalWrite(D10, HIGH);   
  delay(tdelay);                 
  digitalWrite(D10, LOW);
  delay(tdelay);
  digitalWrite(D11, HIGH);   
  delay(tdelay);                 
  digitalWrite(D11, LOW);
  delay(tdelay);
}

void test_button(void) {
if (digitalRead(SW1)&digitalRead(SW4)) digitalWrite(D9, LOW); else digitalWrite(D9, HIGH); 
if (digitalRead(SW2)&digitalRead(SW5)) digitalWrite(D10, LOW); else digitalWrite(D10, HIGH); 
if (digitalRead(SW3)&digitalRead(SW6)) digitalWrite(D11, LOW); else digitalWrite(D11, HIGH); 
}

