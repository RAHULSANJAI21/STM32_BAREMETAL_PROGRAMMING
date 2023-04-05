#include"stm32f4xx.h"
int main()
{
    RCC->AHB1ENR|=0x00000005;
    GPIOA->MODER|=0x00000400;
    GPIOC->MODER&=~0x0C000000;
    
    while(1)
    {
        if(GPIOC->IDR &(1<<13))
        {
            GPIOA->ODR|=0x00000020;
        }
        else
        {
             GPIOA->ODR&=~0x00000020;
        }
    }
}
