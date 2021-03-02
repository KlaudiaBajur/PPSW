#include <LPC21xx.H>
#define LED0_bm 	 0x00010000
#define LED1_bm 	 0x00020000
#define LED2_bm 	 0x00040000
#define LED3_bm 	 0x00080000
#define S0_bm 		 0x00000010
#define S1_bm 		 0x00000020
#define S2_bm 		 0x00000040
#define S3_bm 		 0x00000080

enum ButtonState {RELASED, PRESSED};

void Delay(int iCzas){
    int iDelay = 0;
    for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
    }
void LedInit()
    {
    IO1DIR = (IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm));
    IO0DIR = (IO0DIR | S0_bm);
    }

void LedOn(unsigned char uc_Nr_LED)
{
	switch(uc_Nr_LED)
	{
		case 0: IO1SET = LED0_bm; break;
		case 1: IO1SET = LED1_bm; break;
		case 2: IO1SET = LED2_bm; break;
		case 3: IO1SET = LED3_bm; break;
	}
}

enum ButtonState ReadButton1(void)
{
	if (IO0PIN == (IO0PIN | S0_bm)) return PRESSED;
	else return RELASED;
}
int main(void)
{
		while(1)
	{
		LedInit();
		if (ReadButton1() == PRESSED)
            {
            IO1SET = LED1_bm; IO1CLR = LED0_bm;
            }
		if (ReadButton1() == RELASED)
            {
            IO1SET = LED0_bm; IO1CLR = LED1_bm;
            }
	}
}
