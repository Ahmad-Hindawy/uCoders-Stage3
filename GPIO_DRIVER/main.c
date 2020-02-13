

/**
 * main.c
 */
#include "GPIO_DRIVER.h"
#define REG  volatile long int *
#define CLK_BASE_ADD        0x400FE000
#define FB(offset) (offset)+F_BASE
#define add_off(offset)  *((volatile unsigned long int *)((offset)+CLK_BASE_ADD))
#define RCC  add_off(0x060)
REG GPIOHBCTL = 0x400FE06C;
REG RCGCGPIO = 0x400FE608;
int main(void)
{
        RCC |= (1<<11); // setting the bypass bit
       RCC &= ~(1<<22); // clearing the usesysdiv bit

       //second step (internal osc)
       RCC &= ~(1<<5);
       RCC |= (1<<4);


       RCC |=  (1<<13); //powerdown for pll

       //GPIO INIT
       *GPIOHBCTL |= (1<<5); // GPIO on AHB
       *RCGCGPIO |= (1<<5);//clock enable for port f

       *GPIOHBCTL |= (1<<5); // GPIO on AHB
              *RCGCGPIO |= (1<<5);

       GPIOvoidPinMode(GPIO_PORTF, GPIO_PIN1, GPIO_DIR_OUT, GPIO_8mA, GPIO_PUSH_PULL);
       GPIOvoidPinMode(GPIO_PORTF, GPIO_PIN4, GPIO_DIR_IN, GPIO_8mA, GPIO_PUSH_PULL);
       GPIOvoidSetPin(GPIO_PORTF, GPIO_PIN1, GPIO_HIGH);
/*while (1){
       if(GPIOvoidGetPin(GPIO_PORTF, GPIO_PIN4) == GPIO_HIGH){
           GPIOvoidSetPin(GPIO_PORTF, GPIO_PIN1, GPIO_HIGH);
       }
       else{
           GPIOvoidSetPin(GPIO_PORTF, GPIO_PIN1, GPIO_LOW);
       }


}*/
	return 0;
}
