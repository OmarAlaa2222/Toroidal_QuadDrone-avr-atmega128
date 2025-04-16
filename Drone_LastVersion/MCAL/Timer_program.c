/*
 * Timer_program.c
 *
 *  Created on: May 1, 2023
 *      Author: ElRuby
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "Timer_interface.h"
#include "Timer_register.h"


void TIM1_voidInitialize(void){
	//SETTING NON INVERTING MODE
	CLR_BIT(TCCR1A_Register,6);
	SET_BIT(TCCR1A_Register,7);
	CLR_BIT(TCCR1A_Register,4);
	SET_BIT(TCCR1A_Register,5);

	//SETTING FAST PWM MODE
	CLR_BIT(TCCR1A_Register,0);
	SET_BIT(TCCR1A_Register,1);
	SET_BIT(TCCR1B_Register,3);
	SET_BIT(TCCR1B_Register,4);

	//SET PRESCALAR
	CLR_BIT(TCCR1B_Register,0);
	SET_BIT(TCCR1B_Register,1);
	CLR_BIT(TCCR1B_Register,2);

}

void TIM3_voidInitialize(void){
	//SETTING NON INVERTING MODE
	CLR_BIT(TCCR3A_Register,6);
	SET_BIT(TCCR3A_Register,7);
	CLR_BIT(TCCR3A_Register,4);
	SET_BIT(TCCR3A_Register,5);

	//SETTING FAST PWM MODE
	CLR_BIT(TCCR3A_Register,0);
	SET_BIT(TCCR3A_Register,1);
	SET_BIT(TCCR3B_Register,3);
	SET_BIT(TCCR3B_Register,4);

	//SET PRESCALAR
	CLR_BIT(TCCR3B_Register,0);
	SET_BIT(TCCR3B_Register,1);
	CLR_BIT(TCCR3B_Register,2);

}

void TIM1_voidSetTimerReg(u16 Copy_u16Value){
	ICR1_Register=Copy_u16Value;
}

void TIM3_voidSetTimerReg(u16 Copy_u16Value){
	ICR3L_Register=Copy_u16Value;
}

void TIM1_A_voidSetCompareVal(u16 Copy_u16Value){
	OCR1A_Register=Copy_u16Value;
}

void TIM1_B_voidSetCompareVal(u16 Copy_u16Value){
	OCR1B_Register=Copy_u16Value;
}

void TIM3_A_voidSetCompareVal(u16 Copy_u16Value){
	OCR3A_Register=Copy_u16Value;
}

void TIM3_B_voidSetCompareVal(u16 Copy_u16Value){
	OCR3B_Register=Copy_u16Value;
}

void TIM3_C_voidSetCompareVal(u16 Copy_u16Value){
	OCR3C_Register=Copy_u16Value;
}









