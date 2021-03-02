#include <LPC21xx.H>

void Delay(int iCzas)
    {
    int iDelayCounter = 0;
    for(iDelayCounter = 0; iDelayCounter <=(iCzas*5455); iDelayCounter++);
    }

int main(void)
{
    IO1DIR = 0x00010000;
    while(1)
	{
		IO1SET = 0x00010000;
		Delay(1000);
		IO1CLR = 0x00010000;
		Delay(1000);
	}
}
