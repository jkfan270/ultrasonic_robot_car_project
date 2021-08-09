/*
main function for two HCSR04 Ultrasonic Distance sensors
*/
#include "ultrasonic.h"
#include "stm32f10x.h"
#include "clock.h"
#include "utils.h"


//Initialize the sensors
void initialize_ultrasonic() {
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	
	//Enable pin PB14 and PB15
	//PB14 for trigger pin
  GPIOB->CRH &= ~GPIO_CRH_CNF14_0 & ~GPIO_CRH_CNF14_1;
  GPIOB->CRH |= GPIO_CRH_MODE14_0 | GPIO_CRH_MODE14_1;
	//PB15 for echo pin
  GPIOB-> CRH &= ~GPIO_CRH_CNF15_0;
  GPIOB-> CRH |= GPIO_CRH_CNF15_1;
	
	//Enbale pin PB3 and PB4
	//PB3 for trigger pin
	GPIOB->CRL &= ~GPIO_CRL_CNF3_0 & ~GPIO_CRL_CNF3_0;
  GPIOB->CRL |= GPIO_CRL_MODE3_0 | GPIO_CRL_MODE3_1;
	//PB4 for echo pin
  GPIOB->CRL &= ~GPIO_CRL_CNF4_0;
  GPIOB->CRL |= GPIO_CRL_CNF4_1;
	
}

//Sending the trigger function for sensor 1
void sendTrigger() {
  GPIOB->BSRR |= GPIO_BSRR_BS14;
  delay(60); 
  GPIOB->BSRR |= GPIO_BSRR_BR14;
	
}

//Read the input from sensor 1
struct ultrasonic_context_t readInput() 
{
  struct ultrasonic_context_t dist;
  dist.high_level_time = 0;
  dist.distance = 0;
  sendTrigger();
  while (!(GPIOB->IDR & GPIO_IDR_IDR15)) {}
  while (GPIOB->IDR & GPIO_IDR_IDR15)
    dist.high_level_time++; 
  dist.distance = dist.high_level_time / 58;
  return dist;
}

//Sending the trigger function for sensor 2
void sendTrigger2() {
	GPIOB->BSRR |= GPIO_BSRR_BS3;
	delay(60); 
	GPIOB->BSRR |= GPIO_BSRR_BR3;
	
}

//Read the input from sensor 2
struct ultrasonic_context_t readInput2() 
{
  struct ultrasonic_context_t dist;
  dist.high_level_time = 0;
  dist.distance = 0;
  sendTrigger2();
  while (!(GPIOB->IDR & GPIO_IDR_IDR4)) {}
  while (GPIOB->IDR & GPIO_IDR_IDR4)
    dist.high_level_time++; 
  dist.distance = dist.high_level_time / 58;
  return dist;
}