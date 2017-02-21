#include "Stick.h"
#include "GPIO.h"
#include "Config.h"

#include <iostream>

using namespace std;
using namespace exploringRPi;

Stick::Stick(unsigned gpioNum, float minV, float maxV, GPIO_VALUE onVal)
	:_gpio_num(gpioNum), 
	_min_v(minV), 
	_max_v(maxV),
	_dacDriver(I2CBUS_NUM, I2C_ADDR),
	_gpio(gpioNum),
	_onValue(onVal)	
{
	_gpio.setDirection(OUTPUT);
	turnOffGPIO();
}

Stick::~Stick()
{
	turnOffGPIO();
	_gpio.setDirection(INPUT);
}

void Stick::go(float f)
{
	turnOnGPIO();
	_dacDriver.setOutput(_min_v + (_max_v - _min_v) * f / 100.f);
	
	cout << "I2C Value set to " << _dacDriver.getLastValue() << endl;
	turnOffGPIO();
}

void Stick::turnOnGPIO()
{
	_gpio.setValue(GPIO_VALUE(_onValue & 1));

	cout << "GPIO [" << _gpio_num << "] is On @ " 
	     << _gpio.getValue()  << endl;	
}

void Stick::turnOffGPIO()
{
	_gpio.setValue(GPIO_VALUE((!_onValue) & 1));

	cout << "GPIO [" << _gpio_num << "] is Off @ " 
	     << _gpio.getValue()  << endl;	
}
