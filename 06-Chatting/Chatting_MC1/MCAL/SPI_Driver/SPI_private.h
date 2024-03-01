/*
 * SPI_private.h
 *
 *  Created on: Oct 31, 2023
 *      Author: DELL
 */

#ifndef SPI_DRIVER_SPI_PRIVATE_H_
#define SPI_DRIVER_SPI_PRIVATE_H_


/* SPI */
/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0

#endif /* SPI_DRIVER_SPI_PRIVATE_H_ */
