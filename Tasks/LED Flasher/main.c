

/**
 * this code will blink an led at a rate of 1 sec(aprox) using timer 0 A
 * the chosen system freq is 16MHz so the in order to count for nearly 1 second (1.04 sec to be exact)
 * i used a 16 bit timer and an 8 bit prescaler so it gives a total of 24 bits resolution
 */
#include <gpio.h>
#define REG  volatile unsigned long int *
#define CLK_BASE_ADD        0x400FE000
#define add_off(offset)  *((volatile unsigned long int *)((offset)+CLK_BASE_ADD))
#define RCC  add_off(0x060)

REG EN0 = 0xE000E100;

REG GPTMCFG     = 0x40030000;
REG GPTMTAMR    = 0X40030004;
REG GPTMCTL     = 0X4003000C;
REG GPTMIMR     = 0X40030018;
REG GPTMICR     = 0X40030024;
REG GPTMTAILR   = 0X40030028;
REG GPTMTAPR    = 0X40030038;
REG RCGCTIMER   = 0x400FE604;

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

    GPIODirModeSet(PORTF, 0x2, MODE_OUT);
    GPIOPadSet(PORTF, 0x2, Drive_8mA, PAD_NPU_NPD);
    GPIOWrite(PORTF, 0x2, 0);

    *RCGCTIMER |= 1<<0; // enable clock to timer 0

    *EN0 |= 1<<19; // the main interrupt enable

    *GPTMCTL &= ~(1<<0); //disabling the timer to config
    *GPTMCFG = 0x00000004;
    *GPTMTAMR |= 0x2; //choosing periodic mode and counting down
    *GPTMTAILR = 0x0000ffff; // the load value
    *GPTMTAPR |= 0xFF; // 8 bit prescalar
    *GPTMIMR |= 1<<0; // enabling the timeout interrupt
    *GPTMCTL |= 1<<1; // enabling timer a stall
    *GPTMCTL |= 1<<0; // enabling the timer
while(1){
    if (flag){
        GPIOWrite(PORTF, 0x2, 0x2);
    }
    else{
        GPIOWrite(PORTF, 0x2, 0);
    }
}
    return 0;

}

void timer0A_ISR(void){
 flag = !flag;
 *GPTMICR |= 1<<0; // clearing the interrupt to start counting again
}


