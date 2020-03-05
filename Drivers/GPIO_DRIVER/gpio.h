/*
 * gpio.h
 *
 *  Created on: 14 Feb 2020
 *      Author: AbdulRahman
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "regmap.h"

typedef enum {MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3} gpio_mode_t;
typedef enum {PORTA = 0, PORTB = 2, PORTC = 4,PORTD = 6,PORTE= 8 ,PORTF = 10} gpio_port_t;
typedef enum {APB= 0,AHB = 1} gpio_bus_t;
typedef enum {Drive_2mA = GPIODR2R, Drive_4mA = GPIODR4R, Drive_8mA = GPIODR8R , Drive_8mA_Slew } gpio_drive_t;
typedef enum {Pad_PU = GPIOPUR ,Pad_PD = GPIOPDR ,PAD_NPU_NPD,PAD_OD = GPIOODR } gpio_pad_t;
typedef enum {INT_EDGE = 0x00,INT_LEVEL = 0xFF} gpio_int_t;
typedef enum {EVENT_HIGH = 0x00,EVENT_LOW = 0xFF,INT_BOTH = 0x3 } gpio_event_t;
typedef enum {MASKED = 0x00,UNMASKED = 0xFF} gpio_mask_t;
//Functions prototype

void GPIOBusSet(gpio_port_t port,gpio_bus_t bus);
gpio_bus_t GPIOBusGet(gpio_port_t port);

void GPIOClockSet(gpio_port_t port);
void GPIOClockRst(gpio_port_t port);
char GPIOClockGet(gpio_port_t port);

void GPIODirModeSet(gpio_port_t port, unsigned char pins, gpio_mode_t Mode);
unsigned char GPIODirGet(gpio_port_t port, unsigned char pins);
unsigned char GPIOModeGet(gpio_port_t port, unsigned char pins);

void GPIOPadSet(gpio_port_t port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad);
unsigned char GPIOPadDriveStrGet(gpio_port_t port, unsigned char pins);
unsigned char GPIOPadOpenDrainGet(gpio_port_t port, unsigned char pins);
unsigned char GPIOPadPullUpGet(gpio_port_t port, unsigned char pins);
unsigned char GPIOPadPullDownGet(gpio_port_t port, unsigned char pins);

void GPIOInterruptEventSet(gpio_port_t port, unsigned char pins, gpio_int_t type,gpio_event_t event);
void GPIOInterruptMaskSet(gpio_port_t port, unsigned char pins, gpio_mask_t mask);
void GPIOInterruptClear(gpio_port_t port, unsigned char pins);
unsigned char GPIOInterruptRawGet(gpio_port_t port, unsigned char pins);
unsigned char GPIOInterruptMaskGet(gpio_port_t port, unsigned char pins);

unsigned char GPIORead(gpio_port_t port, unsigned char pins);
void GPIOWrite(gpio_port_t port, unsigned char pins, unsigned char data);

#endif /* GPIO_H_ */
