/* Fussgaengerampel.c */
#include <stdio.h>
#include "myAVR_Board.h"

int main(void)
{
	int i;
	initBoard();

	printf("Fußgaenger kommt!!\n");
	while(1)
	{
		
		if(TASTER1_BETAETIGT) {
			LED_GELB_AN();
			// 1843200 / 1000Hz = 1843
			summer(START, 1843);
			delay(10); // 0,1s
			summer(STOP,0);
			delay(190);
			LED_GELB_AUS();
			LED_ROT_AN();
			summer(START, 8014);  //230 Hz
			
			for(i=8014;i>=4014;i=i-4){
				summer(CONTINUE, i);
				delay(1);
			}

			summer(STOP, 4014); //460 Hz
			delay(200);
			LED_GELB_AN();
			delay(200);
			LED_ROT_AUS();
			LED_GELB_AUS();
			LED_GRUEN_AN();
			delay(200);
			LED_GRUEN_AUS();
		} else {
			LED_ROT_AUS();
			LED_GELB_AUS();
			LED_GRUEN_AUS();
			}
	}

	return 0;

}
