/*
	Clock configuration for LCD and Motor Driver
*/

#include "stm32f10x.h"
#include "clock.h"

void clockInit(void)
{
    uint32_t temp = 0x00;
    //If you hover over the RCC you can go to the definition and then
    //see it is a structure of all the RCC registers.  Then you can
    //simply assign a value.
    RCC->CFGR = 0x00050002;     // Output PLL/2 as MCO,
                                // PLLMUL X3, PREDIV1 is PLL input

    RCC->CR =  0x01010081;      // Turn on PLL, HSE, HSI
 
    while (temp != 0x02000000)  // Wait for the PLL to stabilize
    {
        temp = RCC->CR & 0x02000000; //Check to see if the PLL lock bit is set
    }
		
		RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN
    | RCC_APB2ENR_IOPAEN| RCC_APB2ENR_TIM1EN | RCC_APB2ENR_TIM17EN | RCC_APB2ENR_AFIOEN	;;
	
		
		//CNF FOR LCD
		//Configure the LCD Screen
		
		GPIOB->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 ;
		GPIOB->CRL &= ~GPIO_CRL_CNF0_0 & ~GPIO_CRL_CNF0_1 ;
		
		GPIOB->CRL |= GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0 ;
		GPIOB->CRL &= ~GPIO_CRL_CNF1_0 & ~GPIO_CRL_CNF1_1 ;
		
		GPIOB->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0 ;
		GPIOB->CRL &= ~GPIO_CRL_CNF5_0 & ~GPIO_CRL_CNF5_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF0_0 & ~GPIO_CRL_CNF0_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF1_0 & ~GPIO_CRL_CNF1_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE2_1 | GPIO_CRL_MODE2_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF2_0 & ~GPIO_CRL_CNF2_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE3_1 | GPIO_CRL_MODE3_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF3_0 & ~GPIO_CRL_CNF3_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE4_1 | GPIO_CRL_MODE4_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF4_0 & ~GPIO_CRL_CNF4_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF5_0 & ~GPIO_CRL_CNF5_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF6_0 & ~GPIO_CRL_CNF6_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF7_0 & ~GPIO_CRL_CNF7_1 ;
		
}


//configure motor driver
void motor_driver_init(void)
{
	
	  GPIOA->CRH |= GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0|GPIO_CRH_CNF8_1 ;
		GPIOA->CRH &= ~GPIO_CRH_CNF8_0;
	
		GPIOB->CRH |= GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0|GPIO_CRH_CNF9_1 ;
		GPIOB->CRH &= ~GPIO_CRH_CNF9_0;
	
	

	 GPIOB->CRH |= GPIO_CRH_MODE10 | GPIO_CRH_MODE11 | GPIO_CRH_MODE12| GPIO_CRH_MODE13;
	 GPIOB->CRH &= ~GPIO_CRH_CNF10 & ~GPIO_CRH_CNF11 & ~GPIO_CRH_CNF12& ~GPIO_CRH_CNF13;
	

	
}
