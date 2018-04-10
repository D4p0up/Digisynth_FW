/* DIGISYNTH Firmware V0.02*/

#include "digisynth.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthSimpleDrum     drum1;          //xy=334,252
AudioOutputAnalog        dac1;           //xy=555,251
AudioConnection          patchCord1(drum1, dac1);
// GUItool: end automatically generated code


// Global Variables
unsigned char buttons;
unsigned int freq=0;
/*=============================================================================
 * INIT : Called once at Startup
 *=============================================================================*/
void setup() {
  pins_init();        // Setting Proper pin states
  AudioMemory(15);
  AudioNoInterrupts();  
  drum1.frequency(100);
  drum1.length(100);
  AudioInterrupts();  
  test_full_loop(100); // LED Pulses for Setup Exit
}

/*=============================================================================
 * MAIN LOOP - Repeated
 *=============================================================================*/
void loop() {
if (!digitalRead(SW1)) {
  drum1.noteOn();
  digitalWrite(D9,HIGH);
} else digitalWrite(D9,LOW);
//test_full_loop(100);
//test_led_loop(100);
//test_button();
}


// ___________________
// Functions herebelow 

/*=============================================================================
 * pins_init : Sets Pins inputs and outputs at proper direction
 *=============================================================================*/
void pins_init(void) {
  pinMode(SLATCH, OUTPUT);
  pinMode(SMOSI, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(D11, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
  pinMode(SW6, INPUT); 
  pinMode(A14, OUTPUT);         
}
/*=============================================================================
 * test_full_loop : loops among the Whole LEDs
 *=============================================================================*/
void test_full_loop(unsigned int tdelay) {
  digitalWrite(D11, HIGH);   
  delay(tdelay);                 
  digitalWrite(D11, LOW);
  digitalWrite(D9, HIGH);   
  delay(tdelay);                 
  digitalWrite(D9, LOW);
  digitalWrite(D10, HIGH);   
  delay(tdelay);                 
  digitalWrite(D10, LOW);
  buttons = D8;
  setbuttons();
  delay(tdelay);
  buttons = D1;
  setbuttons();
  delay(tdelay);
  buttons = D2;
  setbuttons();
  delay(tdelay);
  buttons = D3;
  setbuttons();
  delay(tdelay);
  buttons = D4;
  setbuttons();
  delay(tdelay);
  buttons = D5;
  setbuttons();
  delay(tdelay);
  buttons = D6;
  setbuttons();
  delay(tdelay);
  buttons = D7;
  setbuttons();
  delay(tdelay);
  buttons = 0;
  setbuttons();    
}
/*=============================================================================
 * test_led_loop : loops among the 3 Direct LEDS D9, D10 and D11
 *=============================================================================*/
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
/*=============================================================================
 * test_button : basic loop that reads switches and enables three direct LEDs
 *=============================================================================*/
void test_button(void) {
if (digitalRead(SW1)&digitalRead(SW4)) digitalWrite(D9, LOW); else digitalWrite(D9, HIGH); 
if (digitalRead(SW2)&digitalRead(SW5)) digitalWrite(D10, LOW); else digitalWrite(D10, HIGH); 
if (digitalRead(SW3)&digitalRead(SW6)) digitalWrite(D11, LOW); else digitalWrite(D11, HIGH); 
}
/*=============================================================================
 * setbuttons : Pushes 8 status LEDs from "buttons" global variable
 *=============================================================================*/
void setbuttons(void) {
digitalWrite(SLATCH, LOW);
shiftOut(SMOSI, SCLK, MSBFIRST, buttons);
digitalWrite(SLATCH, HIGH);
}
