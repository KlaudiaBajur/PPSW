#include <LPC21xx.H>

#define LED0_bm 	 0x00010000
#define LED1_bm 	 0x00020000
#define LED2_bm 	 0x00040000
#define LED3_bm 	 0x00080000

#define S0_bm 		 0x00000010
#define S1_bm 		 0x00000020
#define S2_bm 		 0x00000040
#define S3_bm 		 0x00000080

enum ButtonState {BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3, RELASED};
enum StepsLeds {ToRight, ToLeft};

void Delay(int iCzas){
	int iDelay = 0;
  for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
}
void LedInit(){
  IO1DIR = (IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm);
}
void KeyboardInit(){
  IO0DIR = (IO0DIR & !(S0_bm | S1_bm | S2_bm | S3_bm));
}

void LedOn(unsigned char uc_Nr_LED){
	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	switch(uc_Nr_LED){
		case 0: IO1SET = LED0_bm; break;
		case 1: IO1SET = LED1_bm; break;
		case 2: IO1SET = LED2_bm; break;
		case 3: IO1SET = LED3_bm; break;
		default: break;
	}
}

enum ButtonState eKeyboardRead(){
	if ((IO0PIN & S0_bm) == 0) return BUTTON_0;
	if ((IO0PIN & S2_bm) == 0) return BUTTON_1;
	if ((IO0PIN & S1_bm) == 0) return BUTTON_2;
	if ((IO0PIN & S3_bm) == 0) return BUTTON_3;
	else return RELASED;
}

void LedStep(enum StepsLeds eKierunek){
	static unsigned int suiTurnToSide;
	if (eKierunek == ToLeft){
		suiTurnToSide++;
	}
	if (eKierunek == ToRight){
		suiTurnToSide--;
	}
	LedOn(suiTurnToSide%4);
}

void LedStepRight(void){
  LedStep(ToRight);
  }
void LedStepLeft(void){
  LedStep(ToLeft);
  }

int main(void){
	LedInit();
	KeyboardInit();
	while(1){
		 Delay(250);
		 switch(eKeyboardRead()){
       case BUTTON_1: LedStepRight(); break;
		   case BUTTON_2: LedStepLeft(); break;
			 default: break;
		 }
	}
}
