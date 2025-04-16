/*
 * ADC_register.h
 *
 *  Created on: Sep 23, 2022
 *      Author: aminz
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX_Reg 	*((volatile u8*)0x7C) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x7A) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x79) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x78) 		// ADC Low Register

#define ADC_Reg 	*((volatile u16*)0x78) 		// ADC all Register


#endif /* ADC_REGISTER_H_ */
