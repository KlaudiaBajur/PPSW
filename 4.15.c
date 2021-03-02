#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

void Delay(int iCzas)
    {
    int iDelay = 0;
    for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
    }
void LedInit()
    {
    IO1DIR = (IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm)); IO1SET = LED0_bm;
    }

int LedOn(unsigned char uc_Nr_LED)
{
	switch(uc_Nr_LED)
	{
		case 0: IO1SET = LED0_bm; break;
		case 1: IO1SET = LED1_bm; break;
		case 2: IO1SET = LED2_bm; break;
		case 3: IO1SET = LED3_bm; break;
	}
}

int main(void)
{
		while(1)
	{
		LedInit();
		LedOn(3);
	}
}
