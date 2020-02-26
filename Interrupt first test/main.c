

/**
 * main.c
 */
#include <gpio.h>
#define REG  volatile unsigned long int *
#define CLK_BASE_ADD        0x400FE000
#define add_off(offset)  *((volatile unsigned long int *)((offset)+CLK_BASE_ADD))
#define RCC  add_off(0x060)

REG EN0 = 0xE000E100;
REG GPIOIS = 0x4005D404;
REG GPIOIBE = 0x4005D408;
REG GPIOIEV = 0x4005D40C;
REG GPIOIM = 0x4005D410;
REG GPIORIS = 0x4005D414;
REG GPIOMIS = 0x4005D418;
REG GPIOICR = 0x4005D41C;

REG C_GPIOIS = 0x4005A404;
REG C_GPIOIBE = 0x4005A408;
REG C_GPIOIEV = 0x4005A40C;
REG C_GPIOIM = 0x4005A410;
REG C_GPIORIS = 0x4005A414;
REG C_GPIOMIS = 0x4005A418;
REG C_GPIOICR = 0x4005A41C;
volatile char flag = 0;
int main(void)
{
    RCC |= (1<<11); // setting the bypass bit
    RCC &= ~(1<<22); // clearing the usesysdiv bit

    //second step (internal osc)
    RCC &= ~(1<<5);
    RCC |= (1<<4);


    RCC |=  (1<<13); //powerdown for pll
    GPIOBusSet(PORTF, AHB);
    GPIOClockSet(PORTF);//clock enable for port f

    GPIOBusSet(PORTC, AHB);
    GPIOClockSet(PORTC);//clock enable for port f

    GPIODirModeSet(PORTF, 0x6, MODE_OUT);
    GPIOPadSet(PORTF, 0x6, Drive_8mA, PAD_NPU_NPD);

    GPIODirModeSet(PORTF, 0x10, MODE_IN);
    GPIOPadSet(PORTF, 0x10, Drive_8mA, Pad_PU);

    GPIODirModeSet(PORTC, 0x80, MODE_IN);
    GPIOPadSet(PORTC, 0x80, Drive_8mA, PAD_NPU_NPD);

    *GPIOIM &= 0x00; // masking the interrupts of switches
    *GPIOIS |= 1<<4; // level trigger on switch 1 , low level by default

    *GPIOICR |= (1<<4); // clearing the flag
    *GPIOIM |= 0x10; // erasing the mask


    *EN0 |= 1<<30; // enabling portf interrupts from NVIC


    *C_GPIOIM &= 0x00; // masking the interrupts of switches
    *C_GPIOIS &= ~(1<<7); // edge trigger on switch 1
    *C_GPIOIEV |= 1<<7; // rising edge
    *C_GPIOICR |= (1<<7); // clearing the flag
    *C_GPIOIM |= (1<<7); // erasing the mask


    *EN0 |= 1<<2; // enabling portc interrupts from NVIC
    while(1){
        GPIOWrite(PORTF, 0x04, 0x00);
        //GPIOWrite(PORTF, 0x02, 0x00);
       if (flag)
        GPIOWrite(PORTF, 0x02, 0x02);
       else
        GPIOWrite(PORTF, 0x02, 0x00);
    }
	return 0;

}

void  GPIOF_ISR(){
   if((*GPIORIS)&(1<<4))
   GPIOWrite(PORTF, 0x04, 0x04);

}
void  GPIOC_ISR(){
   if((*C_GPIORIS)&(1<<7))
       flag = !flag;
   *C_GPIOICR |= 1<<7;
}
