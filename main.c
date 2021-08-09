/*
main file for this project
*/
#include "pwm.h"
#include "clock.h"
#include "lcd.h"
#include "ultrasonic.h"

//main function
int main(void)
{
	
	clockInit();
  motor_driver_init();
	pwm_init() ;
	initialize_lcd();
	initialize_ultrasonic();
	uint32_t distance;
	uint32_t distance2;

	
	while(1)
	{
		  
		//print the distance info for sensor 1
		print_decimal_formatted(LCD_LN1, "Distance: %03d cm",readInput().distance);
       distance=readInput().distance;
		//print the distance info for sensor 2
	print_decimal_formatted(LCD_LN2, "Distance: %03d cm",readInput2().distance);
     distance2=readInput2().distance;
	
		//configure motoring condition
	  if (distance > 30 && distance2 > 30) {
       turn_left();

		}
		else if(distance < 30)
		{
			forward();
		}


		
	}
		
	}