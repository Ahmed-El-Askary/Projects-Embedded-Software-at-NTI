/*
 * SPI.h
 *
 *  Created on: Oct 31, 2023
 *      Author: DELL
 */

#ifndef SPI_DRIVER_SPI_H_
#define SPI_DRIVER_SPI_H_

#include "std_types.h"
#include "common_macros.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "DIO.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SPI_DEFAULT_DATA_VALUE 0xFF

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void SPI_initMaster(void);

void SPI_initSlave(void);

u8 SPI_sendReceiveByte(u8 data);

void SPI_sendString(const u8 *str);

void SPI_receiveString(u8 *str);

#endif /* SPI_DRIVER_SPI_H_ */
