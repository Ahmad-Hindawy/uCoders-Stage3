
#include <gpio.h>
#define REG  volatile long int *
#define CLK_BASE_ADD        0x400FE000
#define FB(offset) (offset)+F_BASE
#define add_off(offset)  *((volatile unsigned long int *)((offset)+CLK_BASE_ADD))
#define RCC  add_off(0x060)

int main(void)
{
       RCC |= (1<<11); // setting the bypass bit
       RCC &= ~(1<<22); // clearing the usesysdiv bit

       //second step (internal osc)
       RCC &= ~(1<<5);
       RCC |= (1<<4);


       RCC |=  (1<<13); //powerdown for pll

       //GPIO INIT
//       GPIOHBCTL |= (1<<5); // GPIO on AHB
       GPIOBusSet(PORTF, AHB);
       gpio_bus_t type = GPIOBusGet(PORTF);
       GPIOClockSet(PORTF);//clock enable for port f
       char clk = GPIOClockGet(PORTF);

       GPIODirModeSet(PORTF, 0x2, MODE_OUT);
       GPIOPadSet(PORTF, 0x2, Drive_8mA, PAD_NPU_NPD);
       GPIODirModeSet(PORTF, 0x10, MODE_IN);
       GPIOPadSet(PORTF, 0x10, Drive_8mA, PAD_NPU_NPD);

while (1){
       if((GPIORead(PORTF, 0x10)>>4)&0x1 ){
           GPIOWrite(PORTF, 0x2, 0xff);
       }
       else{
           GPIOWrite(PORTF, 0x2, 0x00);
       }


}
    return 0;
}
