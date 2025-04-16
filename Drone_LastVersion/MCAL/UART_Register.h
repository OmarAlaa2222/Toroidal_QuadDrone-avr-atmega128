/*
 * UART_Register.h
 *
 *  Created on: May 30, 2023
 *      Author: Lenovo
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR1				*((volatile u8*)0x9C)	/*Data Register Read(Rx)/Write(Tx)*/


#define UCSR1A				*((volatile u8*)0x9B)	/*Control status register A*/

#define UCSRA_RXC1			7
#define UCSRA_TXC1			6
#define UCSRA_UDRE1			5
#define UCSRA_FE1			4
#define UCSRA_DOR1			3
#define UCSRA_PE1			2
#define UCSRA_U2X1			1
#define UCSRA_MPCM1			0


#define UCSR1B				*((volatile u8*)0x9A)	/*Control status register B*/

#define UCSRB_RXCIE1		7
#define UCSRB_TXCIE1		6
#define UCSRB_UDRIE1		5
#define UCSRB_RXEN1			4
#define UCSRB_TXEN1			3
#define UCSRB_UCSZ12		2
#define UCSRB_RXB81			1
#define UCSRB_TXB81			0

#define UBRR1L				*((volatile u8*)0x99)	/*Baud rate register Low*/


#define UCSR1C		*((volatile u8 *)0x9D) 	/*Control status register C / Baud rate register High*/


#define UCSRC_UMSEL1		6						      // Mode Selection:Asynch
#define UCSRC_UPM11			5						      //Parity Mode bit 1
#define UCSRC_UPM10			4						      //Parity Mode bit 0
#define UCSRC_USBS1			3						     //STOP Bit size
#define UCSRC_UCSZ11		2						     //Character Size bit1
#define UCSRC_UCSZ10		1						     // Character Size bit0
#define UCSRC_UCPOL1		0					         //Clock Polarity Bit



#endif /* UART_REGISTER_H_ */
