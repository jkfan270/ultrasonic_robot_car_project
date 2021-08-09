/*
	Main PWM function
*/

#include "stm32f10x.h"
#include "pwm.h"
#include "clock.h"

//pwm initialization
void pwm_init() 
{
	//configure left motor
	TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1
	TIM1->CR2 |= TIM_CR2_OIS1; // Output Idle State for Channel 1 OC1=1 when MOE=0
	TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE |
	TIM_CCMR1_OC1FE; //PWM mode 1, Preload Enable, Fast Enable
	TIM1->CCER |= TIM_CCER_CC1E; //Enable CH1 output on PA8
	TIM1->PSC = 0x03BF; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
	TIM1->ARR = 100; // 100 counts = 10 ms
	TIM1->CCR1 = 200; // 50 counts = 5 ms = 50% duty cycle
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
	TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1

	//configure right motor
	TIM17->CR1 |= TIM_CR1_CEN; // Enable Timer1
	TIM17->CR2 |= TIM_CR2_OIS1; // Output Idle State for Channel 1 OC1=1 when MOE=0
	TIM17->EGR |= TIM_EGR_UG; // Reinitialize the counter
	TIM17->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE |
	TIM_CCMR1_OC1FE; //PWM mode 1, Preload Enable, Fast Enable
	TIM17->CCER |= TIM_CCER_CC1E; //Enable CH1 output on Pb9
	TIM17->PSC = 0x03BF; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
	TIM17->ARR = 100; // 100 counts = 10 ms
	TIM17->CCR1 = 200; // 50 counts = 5 ms = 50% duty cycle
	TIM17->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
	TIM17->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1	
}

//Moving forward function
void forward()
{

			//  GPIOB->ODR|= GPIO_ODR_ODR10| GPIO_ODR_ODR12;
			// IN1=1 AND IN3=1;
	       // GPIOB->ODR&=0xEA00;
				GPIOB->ODR=0X0000;
        GPIOB->ODR|=0xEA00;
       		
	  
}

//Moving backward function
void backward()
{

				//  GPIOB->ODR|= GPIO_ODR_ODR10| GPIO_ODR_ODR12; 
				// IN1=1 AND IN3=1;
	       // GPIOB->ODR&=0xEA00;
				GPIOB->ODR=0X0000;
        GPIOB->ODR|=0x8000;
       		
	  
}


//Turning right function
void turn_right()
{
	 // IN1=0 AND IN3=1; 
   GPIOB->ODR|=GPIO_ODR_ODR12;
	
}


//Turning left function
void turn_left()
{
	// IN1=1 AND IN3=0; 
  GPIOB->ODR|=GPIO_ODR_ODR10; 

	
	
}

//Stoping the motor function
void stop()
{
  
	
	GPIOB->ODR=0X0000;

	
}


