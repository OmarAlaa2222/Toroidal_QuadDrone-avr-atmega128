/*
 * UART_Program.c
 *
 *  Created on: May 30, 2023
 *      Author: Lenovo
 */

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Register.h"


#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

void UART_voidInit(void){
	u8 Local_u8UCSRC=0;


	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL1);      //Choosing Asychronus Operation

	CLR_BIT(Local_u8UCSRC,UCSRC_UPM11);      //Parity Mode BIT 1 disabled
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM10);       //Parity Mode BIT 0 disabled

	CLR_BIT(Local_u8UCSRC,UCSRC_USBS1);     // Choosing 1 BIT for Stop Bit Selection


	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ11);     // Choosing Character Size for 8 bit
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ10);


	CLR_BIT(Local_u8UCSRC,UCSRC_UCPOL1);   //Clock Polarity Rising

	UCSR1C=Local_u8UCSRC;

	UBRR1L=BOUAD_RATE;


	SET_BIT(UCSR1B,UCSRB_RXEN1);  //ENABLE RX
	SET_BIT(UCSR1B,UCSRB_TXEN1);  //ENABLE TX


}


void UART_voidSendData(u8 Copy_u8Data){

	u8 Local_u8Flag;

	while (Local_u8Flag == 0){

	Local_u8Flag=GET_BIT(UCSR1A,UCSRA_UDRE1);
	}

	UDR1 = Copy_u8Data;



}


u8 UART_u8ReceiveData(){
	u8 Local_u8Flag,Local_u8Count;

	while (Local_u8Flag == 0  && Local_u8Count <= USART_TIME_OUT){

		Local_u8Flag=GET_BIT(UCSR1A,UCSRA_RXC1);
	}
	Local_u8Count = 0;
	return UDR1;


}
