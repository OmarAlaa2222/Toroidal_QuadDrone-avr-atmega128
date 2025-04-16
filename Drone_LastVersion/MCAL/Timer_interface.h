/*
 * Timer_interface.h
 *
 *  Created on: May 1, 2023
 *      Author: ElRuby
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_FALLING_EDGE 0
#define ICU_RISING_EDGE 1


void TIM1_voidEnableCTCAINT(void);

void TIM1_voidDisableCTCAINT(void);

void TIM1_voidEnableCTCBINT(void);

void TIM1_voidDisableCTCBINT(void);

void TIM1_voidEnableICUINT(void);

void TIM1_voidDisableICUINT(void);

void TIM1_voidInitialize(void);

void TIM1_voidSetTimerReg(u16 Copy_u16Value);

void TIM1_A_voidSetCompareVal(u16 Copy_u16Value);

void TIM1_B_voidSetCompareVal(u16 Copy_u16Value);

void TIM1_voidEnableOVINT(void);

void TIM1_voidDisableOVINT(void);

void TIM1_voidEnableCTCINT(void);

void TIM1_voidDisableCTCINT(void);

u16 TIM1_u16GETCounter(void);

u16 TIM1_u16GETICUValue(void);

void TIM1_voidSetICUEdge(u16 Copy_u8edge);

void TIM1_voidSetOVCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetCTCACallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetCTCBCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetICUCallback( void (*callback_Copy_ptr) (void) );

void TIM3_voidInitialize(void);
void TIM3_voidSetTimerReg(u16 Copy_u16Value);
void TIM3_A_voidSetCompareVal(u16 Copy_u16Value);
void TIM3_B_voidSetCompareVal(u16 Copy_u16Value);
void TIM3_C_voidSetCompareVal(u16 Copy_u16Value);

#endif /* TIMER_INTERFACE_H_ */
