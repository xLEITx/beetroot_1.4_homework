#include <Arduino.h>

#define LED_RED 15
#define LED_BLUE 16
#define BOARD_BUTTON 0
#define OUTER_BUTTON 21

enum Mode{
  SYNC,
  ASYNC
};

bool mode = SYNC;

void listenButtons(){
  if (digitalRead(BOARD_BUTTON) == true && digitalRead(OUTER_BUTTON) == false)
  {
    mode = SYNC;
  }else if (digitalRead(BOARD_BUTTON) == false && digitalRead(OUTER_BUTTON) == true)
  {
    mode = ASYNC;
  }
  
}

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BOARD_BUTTON, INPUT);
  pinMode(OUTER_BUTTON, INPUT_PULLUP);
}

void loop() {

  listenButtons();

  if(mode == SYNC){
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(200);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    delay(200);
  }else if(mode == ASYNC){
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, LOW);
    delay(1000);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
  }
  
}
