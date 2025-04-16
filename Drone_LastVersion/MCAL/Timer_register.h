/*
 * Timer_register.h
 *
 *  Created on: May 1, 2023
 *      Author: ElRuby
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0_Register  *((volatile u8*)0x53)
#define OCR3C_Register  *((volatile u16*)0x82)
#define OCR3B_Register  *((volatile u16*)0x84)
#define OCR3A_Register  *((volatile u16*)0x86)

#define OCR1A_Register  *((volatile u16*)0x4A)
#define OCR1B_Register  *((volatile u16*)0x48)


#define TIFR_Register  *((volatile u8*)0x56)
#define TIMSK_Register  *((volatile u8*)0x57)
#define TCNT0_Register  *((volatile u8*)0x52)

#define TCCR1A_Register  *((volatile u8*)0x4F)
#define TCCR1B_Register  *((volatile u8*)0x4E)
#define TCNT1_Register  *((volatile u16*)0x4C)

#define TCCR3A_Register  *((volatile u8*)0x8B)
#define TCCR3B_Register  *((volatile u8*)0x8A)



#define ICR1_Register  *((volatile u16*)0x46)
#define ICR3L_Register  *((volatile u16*)0x80)


#endif /* TIMER_REGISTER_H_ */
