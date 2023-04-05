#include"stm32f4xx.h"
int main()
{
    RCC->AHB1ENR|=0x00000001;
    GPIOA->MODER|=0x00000400;
    while(1)
    {
        GPIOA->ODR&=~0x00000020;
    }
}
