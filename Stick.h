// Tony Zhang @2017

#ifndef STICK_H
#define STICK_H

#include "DACDriver.h"
#include "GPIO.h"

class Stick
{
	unsigned _gpio_num;
	float	 _lastV;

	exploringRPi::DACDriver _dacDriver;
	exploringRPi::GPIO	_gpio;

	exploringRPi::GPIO_VALUE		_onValue;	

public:
	Stick(unsigned gpioNum, exploringRPi::GPIO_VALUE onVal);
	virtual ~Stick();

	virtual void go(float f); // no sleep afterwards 
	void setVal(float f); // immediate I2C write.

private:
	void turnOnGPIO();
	void turnOffGPIO();
};

#endif
