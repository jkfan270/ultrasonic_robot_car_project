/*
main LCD configuration function
*/

#include "clock.h"
#include "lcd.h"
#include "utils.h"
#include "stm32f10x.h"
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

//Initialize the LCD, configure the pin
void initialize_lcd()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
	GPIOB->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE5;
	GPIOB->CRL &= ~GPIO_CRL_CNF0 &~GPIO_CRL_CNF1 &~GPIO_CRL_CNF5;
	GPIOC->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2 | GPIO_CRL_MODE3 | GPIO_CRL_MODE3 | GPIO_CRL_MODE4 | GPIO_CRL_MODE4 
								| GPIO_CRL_MODE5 | GPIO_CRL_MODE6 | GPIO_CRL_MODE7;
	GPIOC->CRL &= ~GPIO_CRL_CNF0 &~ GPIO_CRL_CNF1 &~ GPIO_CRL_CNF2 &~ GPIO_CRL_CNF3 &~ GPIO_CRL_CNF4 &~ GPIO_CRL_CNF5 &~ GPIO_CRL_CNF6 &~ GPIO_CRL_CNF7;
	delay(16);
	payload_to_lcd(LCD_CMD_MODE, LCD_8B2L);	
	delay(5);
	payload_to_lcd(LCD_CMD_MODE, LCD_8B2L);
	delay(1);
	payload_to_lcd(LCD_CMD_MODE, LCD_8B2L);
	payload_to_lcd(LCD_CMD_MODE, LCD_8B2L);
	payload_to_lcd(LCD_CMD_MODE, LCD_DCB);
}

//Read the data from inputs
void payload_to_lcd(uint8_t mode, uint8_t data)
{
	GPIOB->BSRR = mode & 0x1 ? LCD_DM_ENA : LCD_CM_ENA; 
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data; 
	delay(8000);
	GPIOB->BSRR = mode & 0x1 ? LCD_DM_DIS : LCD_CM_DIS;
	delay(80000);
}

//Print the data on LCD
void print_lcd(uint8_t line, char* cstr)
{
	payload_to_lcd(LCD_CMD_MODE, line);
	for (char c = *cstr; c != '\0'; c = *++cstr)
    payload_to_lcd(LCD_DATA_MODE,c);
}

//Convert the data in decimal format
void print_decimal_formatted(uint8_t line, const char* fmt, ...) {
    char buff[256];
		va_list args;
    va_start(args, fmt);
    vsnprintf (buff, sizeof(buff), fmt, args);
		print_lcd(line,buff);
    va_end(args);
}
	
	
