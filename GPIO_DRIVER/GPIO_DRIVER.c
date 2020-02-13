/*
 * GPIO_DRIVER.c
 *
 *  Created on: Feb 13, 2020
 *      Author: ME
 */
#include "GPIO_DRIVER.h"
void GPIOvoidPinMode(uint32_t Port, uint8_t Pin, uint8_t Direction, uint8_t Strength, uint8_t IOType){
    /*setting the direction*/
    switch(Port){
    case GPIO_PORTA:
        if(Direction == GPIO_DIR_OUT)
        {GPIODIR(GPIO_PORTA_AHB_BASE) |= (1<<Pin);}
        else
            {GPIODIR(GPIO_PORTA_AHB_BASE) &= !(1<<Pin);}
        break;
    case GPIO_PORTB:
        if(Direction == GPIO_DIR_OUT)
        {GPIODIR(GPIO_PORTB_AHB_BASE) |= (1<<Pin);}
        else
        {GPIODIR(GPIO_PORTB_AHB_BASE) &= !(1<<Pin);}
            break;
    case GPIO_PORTC:
        if(Direction == GPIO_DIR_OUT)
        {GPIODIR(GPIO_PORTC_AHB_BASE) |= (1<<Pin);}
        else
        {GPIODIR(GPIO_PORTC_AHB_BASE) &= !(1<<Pin);}
            break;
    case GPIO_PORTD:
        if(Direction == GPIO_DIR_OUT)
        {GPIODIR(GPIO_PORTD_AHB_BASE) |= (1<<Pin);}
        else
        {GPIODIR(GPIO_PORTD_AHB_BASE) &= !(1<<Pin);}
            break;
    case GPIO_PORTE:
        if(Direction == GPIO_DIR_OUT)
        {GPIODIR(GPIO_PORTE_AHB_BASE) |= (1<<Pin);}
        else
        {GPIODIR(GPIO_PORTE_AHB_BASE) &= !(1<<Pin);}
            break;
    case GPIO_PORTF:
        if(Direction == GPIO_DIR_OUT)
        {GPIODIR(GPIO_PORTF_AHB_BASE) |= (1<<Pin);}
        else
        {GPIODIR(GPIO_PORTF_AHB_BASE) &= !(1<<Pin);}
            break;
    }

    /*setting gpio in alt function register*/
    switch(Port){
    case GPIO_PORTA:
            GPIODIR(GPIO_PORTA_AHB_BASE) &= ~(1<<Pin);
            break;
    case GPIO_PORTB:
            GPIOAFSEL(GPIO_PORTB_AHB_BASE) &= ~(1<<Pin);
            break;
    case GPIO_PORTC:
            GPIOAFSEL(GPIO_PORTC_AHB_BASE) &= ~(1<<Pin);
            break;
    case GPIO_PORTD:
            GPIOAFSEL(GPIO_PORTD_AHB_BASE) &= ~(1<<Pin);
            break;
    case GPIO_PORTE:
            GPIOAFSEL(GPIO_PORTE_AHB_BASE) &= ~(1<<Pin);
            break;
    case GPIO_PORTF:
            GPIOAFSEL(GPIO_PORTF_AHB_BASE) &= ~(1<<Pin);
            break;
    }

   /* GPIOODR(GPIO_PORTA_AHB_BASE) &= ~(0xFF);
    GPIOPDR(GPIO_PORTA_AHB_BASE) &= ~(0xFF);
    GPIOPUR(GPIO_PORTA_AHB_BASE) &= ~(0xFF);*/
    /*setting pin strength*/
    switch(Port){
    case GPIO_PORTA:
            switch(Strength){
            case GPIO_2mA:
                GPIODR2R(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_4mA:
                GPIODR4R(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_8mA:
                GPIODR8R(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTB:
            switch(Strength){
            case GPIO_2mA:
                GPIODR2R(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_4mA:
                GPIODR4R(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_8mA:
                GPIODR8R(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTC:
        switch(Strength){
            case GPIO_2mA:
                GPIODR2R(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_4mA:
                GPIODR4R(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_8mA:
                GPIODR8R(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTD:
        switch(Strength){
            case GPIO_2mA:
                GPIODR2R(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_4mA:
                GPIODR4R(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_8mA:
                GPIODR8R(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTE:
        switch(Strength){
            case GPIO_2mA:
                GPIODR2R(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_4mA:
                GPIODR4R(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_8mA:
                GPIODR8R(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTF:
        switch(Strength){
            case GPIO_2mA:
                GPIODR2R(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_4mA:
                GPIODR4R(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_8mA:
                GPIODR8R(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    }


    /*selecting push-pull or open drain*/

    switch(Port){
    case GPIO_PORTA:
            switch(IOType){
            case GPIO_OPEN_DRAIN:
                GPIOODR(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_DOWN:
                GPIOPDR(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_UP:
                GPIOPUR(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTB:
            switch(IOType){
            case GPIO_OPEN_DRAIN:
                GPIOODR(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_DOWN:
                GPIOPDR(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_UP:
                GPIOPUR(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTC:
            switch(IOType){
            case GPIO_OPEN_DRAIN:
                GPIOODR(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_DOWN:
                GPIOPDR(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_UP:
                GPIOPUR(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTD:
            switch(IOType){
            case GPIO_OPEN_DRAIN:
                GPIOODR(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_DOWN:
                GPIOPDR(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_UP:
                GPIOPUR(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTE:
        switch(IOType){
            case GPIO_OPEN_DRAIN:
                GPIOODR(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_DOWN:
                GPIOPDR(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_UP:
                GPIOPUR(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
                break;
            }
            break;
    case GPIO_PORTF:
        switch(IOType){
            case GPIO_OPEN_DRAIN:
                GPIOODR(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_DOWN:
                GPIOPDR(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
                break;
            case GPIO_PULL_UP:
                GPIOPUR(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
                break;
            }
        break;
        }

    /*enable digital input*/
    switch(Port){
    case GPIO_PORTA:
        GPIODEN(GPIO_PORTA_AHB_BASE) |= (1<<Pin);
            break;
    case GPIO_PORTB:
        GPIODEN(GPIO_PORTB_AHB_BASE) |= (1<<Pin);
            break;
    case GPIO_PORTC:
        GPIODEN(GPIO_PORTC_AHB_BASE) |= (1<<Pin);
            break;
    case GPIO_PORTD:
        GPIODEN(GPIO_PORTD_AHB_BASE) |= (1<<Pin);
            break;
    case GPIO_PORTE:
        GPIODEN(GPIO_PORTE_AHB_BASE) |= (1<<Pin);
            break;
    case GPIO_PORTF:
        GPIODEN(GPIO_PORTF_AHB_BASE) |= (1<<Pin);
            break;
    }

}

void GPIOvoidSetPin(uint32_t Port, uint8_t Pin , uint8_t Value){
    switch(Port){
    case GPIO_PORTA:
        if (Value == GPIO_HIGH)
        { GPIODATA((1<<Pin+2),GPIO_PORTA_AHB_BASE) = (1<<Pin); }
        else if(Value == GPIO_LOW){GPIODATA((1<<Pin+2),GPIO_PORTA_AHB_BASE) = (0<<Pin);}
            break;
    case GPIO_PORTB:
        if(Value == GPIO_HIGH)
        {GPIODATA((1<<Pin+2),GPIO_PORTB_AHB_BASE) = (1<<Pin);}
        else if(Value == GPIO_LOW)
        {GPIODATA((1<<Pin+2),GPIO_PORTB_AHB_BASE) = (0<<Pin);}
            break;
    case GPIO_PORTC:
        if(Value == GPIO_HIGH)
        {GPIODATA((1<<Pin+2),GPIO_PORTC_AHB_BASE) = (1<<Pin);}
        else if(Value == GPIO_LOW)
        {GPIODATA((1<<Pin+2),GPIO_PORTC_AHB_BASE) = (0<<Pin);}
            break;
    case GPIO_PORTD:
        if(Value == GPIO_HIGH)
        {GPIODATA((1<<Pin+2),GPIO_PORTD_AHB_BASE) = (1<<Pin);}
        else if(Value == GPIO_LOW)
        {GPIODATA((1<<Pin+2),GPIO_PORTD_AHB_BASE) = (0<<Pin);}
            break;
    case GPIO_PORTE:
        if(Value == GPIO_HIGH)
        {GPIODATA((1<<Pin+2),GPIO_PORTE_AHB_BASE) = (1<<Pin);}
        else if(Value == GPIO_LOW)
        {GPIODATA((1<<Pin+2),GPIO_PORTE_AHB_BASE) = (0<<Pin);}
            break;
    case GPIO_PORTF:
        if(Value == GPIO_HIGH)
        {GPIODATA((1<<Pin+2),GPIO_PORTF_AHB_BASE) = (1<<Pin);}
        else if(Value == GPIO_LOW)
        {GPIODATA((1<<Pin+2),GPIO_PORTF_AHB_BASE) = (0<<Pin);}
            break;
    }
}

uint8_t GPIOvoidGetPin(uint32_t Port, uint8_t Pin){
    switch(Port){
    case GPIO_PORTA:
        if(GPIODATA((1<<Pin+2),GPIO_PORTA_AHB_BASE) == 0)
        {return GPIO_LOW;}
        else
        {return GPIO_HIGH;}
            break;
    case GPIO_PORTB:
        if(GPIODATA((1<<Pin+2),GPIO_PORTB_AHB_BASE) == 0)
        {return GPIO_LOW;}
        else
        {return GPIO_HIGH;}
            break;
    case GPIO_PORTC:
        if(GPIODATA((1<<Pin+2),GPIO_PORTC_AHB_BASE) == 0)
        {return GPIO_LOW;}
        else
        {return GPIO_HIGH;}
            break;
    case GPIO_PORTD:
        if(GPIODATA((1<<Pin+2),GPIO_PORTD_AHB_BASE) == 0)
        {return GPIO_LOW;}
        else
        {return GPIO_HIGH;}
            break;
    case GPIO_PORTE:
        if(GPIODATA((1<<Pin+2),GPIO_PORTE_AHB_BASE) == 0)
        {return GPIO_LOW;}
        else
        {return GPIO_HIGH;}
            break;
    case GPIO_PORTF:
        if(GPIODATA((1<<Pin+2),GPIO_PORTF_AHB_BASE) == 0)
        {return GPIO_LOW;}
        else
        {return GPIO_HIGH;}
            break;
    }
}
