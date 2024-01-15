/*
 * SoftwareSerial.h
 *
 *  Created on: Jan 15, 2024
 *      Author: admin
 */

#ifndef INC_SOFTWARESERIAL_H_
#define INC_SOFTWARESERIAL_H_

#include <stdint.h>

#define SS_MAX_TX_BUFF			128
#define SS_MAX_RX_BUFF			128

//#if(SS_MAX_TX_BUFF == 256)
//	#define	TX_BUFF_SIZE_BIT	8
#if(SS_MAX_TX_BUFF == 128)
	#define	TX_BUFF_SIZE_BIT	7
#elif(SS_MAX_TX_BUFF == 64)
	#define	TX_BUFF_SIZE_BIT	6
#elif(SS_MAX_TX_BUFF == 32)
	#define	TX_BUFF_SIZE_BIT	5
#elif(SS_MAX_TX_BUFF == 16)
	#define	TX_BUFF_SIZE_BIT	4
#else
	#error "Invalid tx buffer size! "
#endif

typedef struct {
	uint8_t pos	:	TX_BUFF_SIZE_BIT;
} tx_uintx_t;

//#if(SS_MAX_RX_BUFF == 256)
//	#define	RX_BUFF_SIZE_BIT	8
#if(SS_MAX_RX_BUFF == 128)
	#define	RX_BUFF_SIZE_BIT	7
#elif(SS_MAX_RX_BUFF == 64)
	#define	RX_BUFF_SIZE_BIT	6
#elif(SS_MAX_RX_BUFF == 32)
	#define	RX_BUFF_SIZE_BIT	5
#elif(SS_MAX_RX_BUFF == 16)
	#define	RX_BUFF_SIZE_BIT	4
#else
	#error "Invalid rx buffer size! "
#endif

typedef struct {
	uint8_t pos	:	RX_BUFF_SIZE_BIT;
} rx_uintx_t;

void sofwareSerialInit(uint32_t baudrate);
void ssWriteByte(char byte);
void ssWrite(const char *data);
uint8_t isRxAvailable();
char ssReadByte();
//extern void TIM3_IRQHandler();

#endif /* INC_SOFTWARESERIAL_H_ */
