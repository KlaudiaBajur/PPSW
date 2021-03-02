#include "Led.h"
#include "Keyboard.h"

void Delay(int iCzas){
		int iDelay = 0;
    for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
    }

int main(void){
	LedInit();
	KeyboardInit();
	while(1){
		 switch(eKeyboardRead()){
			 case BUTTON_1:
				 LedStepRight();
				 Delay(250);
				 break;
		   case BUTTON_2:
				 LedStepLeft();
			   Delay(250);
			   break;
			 default: break;
		 }
	}
}
