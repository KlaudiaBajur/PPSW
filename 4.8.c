#include <LPC21xx.H>

void Delay(int iCzas)
    {
    int iDelay = 0;
    for(iDelay = 0; iDelay <=(iCzas*5455); iDelay++);
    }

int main(void)
{
    IO1DIR = 0x00010000;
    while(1)
	{
		IO1SET = 0x00010000;
		Delay(100);
		IO1CLR = 0x00010000;
		Delay(100);
	}
}
