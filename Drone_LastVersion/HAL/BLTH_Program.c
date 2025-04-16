/*
 * BLTH_Program.c
 *
 *  Created on: May 30, 2023
 *      Author: Lenovo
 */

#include "BLTH_Private.h"
#include "BLTH_Interface.h"
#include "BLTH_Config.h"
#include "../MCAL/UART_Interface.h"


#include "../STD_TYPES.h"
#include "../BIT_MATH.h"


u8 BLTH_ReadingValue;

u8 BLTH_u8GetBluetoothReading(void){

	u8 Local_u8Reading;
	Local_u8Reading = UART_u8ReceiveData();


	if(Local_u8Reading == 'F')
	{
		BLTH_ReadingValue = FORWARD;
	}

	else if(Local_u8Reading == 'B')
		{
			BLTH_ReadingValue = BACKWARD;

		}

	else if (Local_u8Reading == 'L'){

		BLTH_ReadingValue = LEFT;

	}


	else if (Local_u8Reading == 'R'){

		BLTH_ReadingValue = RIGHT;
	}


	else if (Local_u8Reading == 'S'){
		BLTH_ReadingValue = STOP;
	}


	else if (Local_u8Reading == '1'){
			BLTH_ReadingValue = SPEED1;
		}


	else if (Local_u8Reading == '2'){
			BLTH_ReadingValue = SPEED2;
		}


	else if (Local_u8Reading == '3'){
				BLTH_ReadingValue = SPEED3;
			}


	else if (Local_u8Reading == '4'){
				BLTH_ReadingValue = SPEED4;
			}


	else if (Local_u8Reading == '5'){
				BLTH_ReadingValue = SPEED5;
			}


	else if (Local_u8Reading == '6'){
				BLTH_ReadingValue = SPEED6;
			}


	else if (Local_u8Reading == '7'){
				BLTH_ReadingValue = SPEED7;
			}


	else if (Local_u8Reading == '8'){
				BLTH_ReadingValue = SPEED8;
			}


	else if (Local_u8Reading == '9'){
				BLTH_ReadingValue = SPEED9;
			}


	else if (Local_u8Reading == 'q'){
				BLTH_ReadingValue = SPEED10;
			}
	else if (Local_u8Reading == 'V') {
		BLTH_ReadingValue = HOVER_ON;
	}
	else if (Local_u8Reading == 'v'){
		BLTH_ReadingValue = HOVER_OFF;
	}

	return BLTH_ReadingValue;




}
