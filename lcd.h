/*
header file for LCD configuration
*/
#include <stdint.h>

#define LCD_8B2L 0x38 
#define LCD_DCB 0x0F 
#define LCD_MCR 0x06 
#define LCD_CLR 0x01 
#define LCD_LN1 0x80 
#define LCD_LN2 0xC0 
#define LCD_CM_ENA 0x00210002
#define LCD_CM_DIS 0x00230000
#define LCD_DM_ENA 0x00200003
#define LCD_DM_DIS 0x00220001
#define LCD_CMD_MODE 0x00
#define LCD_DATA_MODE 0x001

void initialize_lcd();
void payload_to_lcd(uint8_t mode, uint8_t data);
void print_lcd(uint8_t line, char* cstr);
void print_decimal_formatted(uint8_t line, const char* fmt, ...);
