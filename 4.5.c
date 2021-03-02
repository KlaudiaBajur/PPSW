#include <LPC21xx.H>

void Delay(void)
    {
    int iDelay = 0
    for(iDelay = 0; iDelay <=1499999; iDelay++);
    }

int main(void)
{
    IO1DIR = 0x00010000;
    while(1)
	{
		IO1SET = 0x00010000;
		Delay();
		IO1CLR = 0x00010000;
	}
}
