/*
 * GPIO_DRIVER.h
 *
 *  Created on: Feb 12, 2020
 *      Author: HINDAWY
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#define uint32_t unsigned long int
#define uint8_t unsigned char

/**/
#define add_off(offset,baseadd)     (*((volatile uint32_t*)((offset)+(baseadd))))


/*Base addresses for APB legacy bus
#define GPIO_PORTA_APB_BASE 0x40004000
#define GPIO_PORTB_APB_BASE 0x40005000
#define GPIO_PORTC_APB_BASE 0x40006000
#define GPIO_PORTD_APB_BASE 0x40007000
#define GPIO_PORTE_APB_BASE 0x40024000
#define GPIO_PORTF_APB_BASE 0x40025000*/

/*Base addresses for AHB high speed bus*/
#define GPIO_PORTA_AHB_BASE 0x40058000
#define GPIO_PORTB_AHB_BASE 0x40059000
#define GPIO_PORTC_AHB_BASE 0x4005A000
#define GPIO_PORTD_AHB_BASE 0x4005B000
#define GPIO_PORTE_AHB_BASE 0x4005C000
#define GPIO_PORTF_AHB_BASE 0x4005D000

/*Registers offsets*/
#define GPIODATA(pin,base)        add_off((pin),(base))
#define GPIODIR(base)         add_off(0x400,(base))
#define GPIOAFSEL(base)       add_off(0x420,(base))
#define GPIODR2R(base)        add_off(0x500,(base))
#define GPIODR4R(base)        add_off(0x504,(base))
#define GPIODR8R(base)        add_off(0x508,(base))
#define GPIOODR(base)         add_off(0x50C,(base))
#define GPIOPUR(base)         add_off(0x510,(base))
#define GPIOPDR(base)         add_off(0x514,(base))
#define GPIOSLR(base)         add_off(0x518,(base))
#define GPIODEN(base)         add_off(0x51C,(base))
#define GPIOPCTL(base)        add_off(0x52C,(base))

/*Ports*/
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5

/*Pins*/
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7

#define GPIO_DIR_IN     0
#define GPIO_DIR_OUT    1

#define GPIO_2mA    0
#define GPIO_4mA    1
#define GPIO_8mA    2

#define GPIO_PUSH_PULL  0
#define GPIO_OPEN_DRAIN 1
#define GPIO_PULL_UP    2
#define GPIO_PULL_DOWN  3

#define GPIO_LOW    0
#define GPIO_HIGH   1


void GPIOvoidPinMode(uint32_t Port, uint8_t Pin, uint8_t Direction, uint8_t Strength, uint8_t IOType);
void GPIOvoidSetPin(uint32_t Port, uint8_t Pin , uint8_t Value);
uint8_t GPIOvoidGetPin(uint32_t Port, uint8_t Pin);


#endif /* GPIO_DRIVER_H_ */
