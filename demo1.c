/* demo1.c */
#include <stdio.h>
#include "myAVR_Board.h"

int main(void)
{

	initBoard();

	printf("Programmstart\n");
	while(1)
	{
		if(TASTER1_BETAETIGT)
			LED_ROT_AN();
		else
			LED_ROT_AUS();

		if(TASTER2_BETAETIGT)
		{
			// 1843200 / 1000Hz = 1843
			summer(START, 1843);
			delay(100); // 1s
			summer(STOP,0);
		}
	}

	return 0;

}
