// cpp

#include "DigitalOut.h"

DigitalOut::DigitalOut(gpio_num_t num, gpio_pullup_t pull_up, gpio_pulldown_t pull_down)
	: port(num)
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = 1UL << num;
    io_conf.pull_down_en = pull_down;
    io_conf.pull_up_en = pull_up;
    gpio_config(&io_conf);
}

void DigitalOut::write(int value)
{
	gpio_set_level(port, value);
}

int DigitalOut::read()
{
	uint32_t mask = 1UL << port;
	if (GPIO.out & mask)
	{
		return 1;
	}
	return 0;
}

DigitalOut& DigitalOut::operator=(int value)
{
	write(value);
	return *this;
}

DigitalOut& DigitalOut::operator=(DigitalOut& rhs)
{
	write(rhs.read());
	return *this;
}
