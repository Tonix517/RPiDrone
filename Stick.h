// Tony Zhang @2017

#ifndef STICK_H
#define STICK_H

#include "DACDriver.h"
#include "GPIO.h"

class Stick
{
	unsigned _gpio_num;
	float	 _max_v;
	float	 _min_v;

	exploringRPi::DACDriver _dacDriver;
	exploringRPi::GPIO	_gpio;

	exploringRPi::GPIO_VALUE		_onValue;	

public:
	Stick(unsigned gpioNum, float minV, float maxV, exploringRPi::GPIO_VALUE onVal);
	virtual ~Stick();

	virtual void go(float f); // no sleep afterwards 

private:
	void turnOnGPIO();
	void turnOffGPIO();
};

#endif