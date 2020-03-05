/*
 * regmap.h
 *
 *  Created on: 14 Feb 2020
 *      Author: AbdulRahman
 */

#ifndef REGMAP_H_
#define REGMAP_H_

#define     GPIOHBCTL   *((volatile unsigned long int *)(0x400FE06C))
#define     RCGCGPIO    *((volatile unsigned long int *)(0x400FE608))

#define     GPIODATA        0x000
#define     GPIODIR         0x400
#define     GPIOAFSEL       0x420
#define     GPIODR2R        0x500
#define     GPIODR4R        0x504
#define     GPIODR8R        0x508
#define     GPIOSLR         0x518
#define     GPIOODR         0x50C
#define     GPIOPUR         0x510
#define     GPIOPDR         0x514
#define     GPIOSLR         0x518
#define     GPIODEN         0x51C

#define     GPIOIS          0x404
#define     GPIOIBE         0x408
#define     GPIOIEV         0x40C
#define     GPIOIM          0x410
#define     GPIORIS         0x414
#define     GPIOMIS         0x418
#define     GPIOICR         0x41C




#endif /* REGMAP_H_ */
