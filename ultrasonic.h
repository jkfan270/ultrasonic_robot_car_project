/*
header file for HCSR04 Ultrasonic distance sensors
*/

#include <stdint.h>
struct ultrasonic_context_t
{
	uint32_t high_level_time;
	uint32_t distance;
};

void initialize_ultrasonic();
void sendTrigger();
void sendTrigger2();
struct ultrasonic_context_t readInput();
struct ultrasonic_context_t readInput2();


