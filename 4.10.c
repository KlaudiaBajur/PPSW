#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED3_bm 0x00080000

void Delay(int iCzas)
    {
    int iDelay = 0;
    for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
    }

int main(void)
{
    IO1DIR = LED3_bm;
    while(1)
	{
		IO1SET = LED3_bm;
		Delay(100);
		IO1CLR = LED3_bm;
		Delay(100);
	}
}
