#include"stm32f4xx.h"
int main()
{
    RCC->AHB1ENR|=0x00000005;//enable clock of the port
    GPIOA->MODER|=0x00000400;//select on board led pin as o/p
    GPIOC->MODER&=~0x0C000000;//select on board as input
    
    while(1)
    {
        if(GPIOC->IDR &(1<<13))//check if switch is pressed
        {
            GPIOA->ODR|=0x00000020;//turn on led
        }
        else
        {
             GPIOA->ODR&=~0x00000020;//turn off led
        }
    }
}
