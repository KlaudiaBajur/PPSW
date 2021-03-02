#include <LPC21xx.H>
#define LED0_bm 0x00010000

void Delay(int iCzas)
    {
    int iDelay = 0;
    for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
    }

int main(void)
{
    IO1DIR = LED0_bm;
    while(1)
	{
		IO1SET = LED0_bm;
		Delay(100);
		IO1CLR = LED0_bm;
		Delay(100);
	}
}
