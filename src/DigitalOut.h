#ifndef DIGITALOUT_H_
#define DIGITALOUT_H_

#include "driver/gpio.h"

class DigitalOut
{
	gpio_num_t port;
public:

	DigitalOut(gpio_num_t num, gpio_pullup_t pull_up = GPIO_PULLUP_DISABLE, gpio_pulldown_t pull_down = GPIO_PULLDOWN_DISABLE);
	void write(int value);
	int read();
	DigitalOut& operator=(int value);
	DigitalOut& operator=(DigitalOut& rhs);
	operator int() {
		return read();
	};
};

#endif  // DIGITALOUT_H_
