/*
 * UART_Interface.h
 *
 *  Created on: May 30, 2023
 *      Author: Lenovo
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../STD_TYPES.h"

void UART_voidInit(void);

void UART_voidSendData(u8 Copy_u8Data);

u8 UART_u8ReceiveData(void);

#endif /* UART_INTERFACE_H_ */
