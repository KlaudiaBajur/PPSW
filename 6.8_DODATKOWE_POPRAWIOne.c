#include "Led.h"
#include "Keyboard.h"

enum LedState {LED_LEFT, LED_RIGHT, LED_BLINK, LED_STOP};
enum LedState eLedState = LED_STOP;

int iCounterBlink = 0;
int iLedState = 0;

void Delay(int iCzas){
  for(int iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
}

int main(void){
	LedInit();
	KeyboardInit();
	while(1){
		switch(eLedState){
			case LED_STOP:
				if (eKeyboardRead() == BUTTON_0){
					eLedState = LED_LEFT;
				}
				else if (eKeyboardRead() == BUTTON_2){
					eLedState = LED_RIGHT;
				}
				else if (eKeyboardRead() == BUTTON_3){
					eLedState = LED_BLINK;
				}
				else{
					eLedState = LED_STOP;
				}
				break;
			case LED_LEFT:
				if (eKeyboardRead() == BUTTON_1){
					eLedState = LED_STOP;
				}
				else{
					LedStepLeft();
					eLedState = LED_LEFT;
				}
				break;
			case LED_RIGHT:
				if (eKeyboardRead() == BUTTON_1){
					eLedState = LED_STOP;
				}
				else{
					LedStepRight();
					eLedState = LED_RIGHT;
				}
				break;

			case LED_BLINK:
				if ((10 == iCounterBlink) || (BUTTON_1 == eKeyboardRead())){
					eLedState = LED_STOP;
					iLedState = 0;
					iCounterBlink = 0;
				}
				else{
					if(iLedState != 0){
						LedOn(1);
						iLedState = 0;
						iCounterBlink++;
					}
					else{
						LedOn(4);
						iLedState = 1;
					}
					eLedState = LED_BLINK;
				}
				break;
			default: break;
			}
		Delay(160);
	}
}
