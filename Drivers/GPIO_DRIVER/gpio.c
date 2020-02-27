/*
 * gpio.c
 *
 *  Created on: 14 Feb 2020
 *      Author: AbdulRahman
 */

#include "gpio.h"
unsigned long int base_add [] = {0x40004000,0x40058000,
                                 0x40005000,0x40059000,
                                 0x40006000,0x4005A000,
                                 0x40007000,0x4005B000,
                                 0x40024000,0x4005C000,
                                 0x40025000,0x4005D000};



void GPIOBusSet(gpio_port_t port,gpio_bus_t bus){
    GPIOHBCTL &= ~(1<<(port/2));
    GPIOHBCTL |= (bus<<(port/2));
}
gpio_bus_t GPIOBusGet(gpio_port_t port){
    return (((GPIOHBCTL)>>(port/2)) & 0x1);
}

void GPIOClockSet(gpio_port_t port){
    RCGCGPIO &= ~(1<<(port/2));
    RCGCGPIO |= (1<<(port/2));
}
void GPIOClockRst(gpio_port_t port){
    RCGCGPIO &= ~(1<<(port/2));
}
char GPIOClockGet(gpio_port_t port){
    return (((RCGCGPIO)>>(port/2)) & 0x1);
}

void GPIODirModeSet(gpio_port_t port, unsigned char pins, gpio_mode_t Mode)
{
    gpio_bus_t bus = GPIOBusGet(port);
    unsigned long int address = base_add[port + bus];
    volatile unsigned long int * reg = address + GPIOAFSEL;
    unsigned long int data = *reg;

    data &= ~(pins);
    if (Mode == MODE_AF)
        data |= (0xff & pins);
    else
        data |= (0x00 & pins);

    *reg = data;

    reg = address + GPIODIR;
    data = *reg;
    data &= ~(pins);
    data |= (Mode & pins);
    *reg = data;
}

void GPIOPadSet(gpio_port_t port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad){
    gpio_bus_t bus = GPIOBusGet(port);
    unsigned long int address = base_add[port + bus];
    volatile unsigned long int * reg ;
    unsigned long int data ;

    /*enable slew rate if used*/
    if(str == Drive_8mA_Slew)
    {
        reg = address + GPIOSLR;
        data = *reg;
        data &= ~(pins);
        data |= (pins);
        *reg = data;
        reg = address + GPIODR8R;
    }
    else
        reg = address + str;

    /*setting the strength*/

    data = *reg;
    data &= ~(pins);
    data |= (pins);
    *reg = data;

    /*clearing pull up reg*/
    reg = address + GPIOPUR;
    data = *reg;
    data &= ~(pins);
    *reg = data;

    /*clearing pull down reg*/
    reg = address + GPIOPDR;
    data = *reg;
    data &= ~(pins);
    *reg = data;

    /*clearing open drain reg*/
    reg = address + GPIOODR;
    data = *reg;
    data &= ~(pins);
    *reg = data;

    if(pad != PAD_NPU_NPD){
        reg = address + pad;
        data = *reg;
        data &= ~(pins);
        data |= (pins);
        *reg = data;
    }

    /*digital enabled reg*/
    reg = address + GPIODEN;
    data = *reg;
    data &= ~(pins);
    data |= (pins);
    *reg = data;

}
unsigned char GPIORead(gpio_port_t port, unsigned char pins){
    gpio_bus_t bus = GPIOBusGet(port);
    unsigned long int address = base_add[port + bus];
    volatile unsigned long int * reg  = address + GPIODATA + (pins<<2) ;
    unsigned long int data = *reg ;
    return (data & 0xff);
}
void GPIOWrite(gpio_port_t port, unsigned char pins, unsigned char data){
    gpio_bus_t bus = GPIOBusGet(port);
    unsigned long int address = base_add[port + bus];
    volatile unsigned long int * reg  = address + GPIODATA + (pins<<2) ;
    unsigned long int reg_data = *reg ;
    reg_data = data;
    *reg = reg_data;
}


