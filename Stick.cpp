#include "Stick.h"
#include "GPIO.h"
#include "Config.h"
#include <unistd.h>
#include <cmath>
#include <iostream>

using namespace std;
using namespace exploringRPi;

Stick::Stick(unsigned gpioNum, GPIO_VALUE onVal)
	:_gpio_num(gpioNum), 
	_lastV(0.f),
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

	cout << "From " << _lastV << " to " << f << endl;

	float step = _lastV > f ? -SIGNAL_STEP : SIGNAL_STEP;
	while(abs(_lastV - f) >= SIGNAL_STEP)
	{
		_lastV += step;
		_dacDriver.setOutput(_lastV);
		cout << "I2C Value set to " << _dacDriver.getLastValue() << endl;
		usleep(SIGNAL_INTERVAL);			
	}
		
	turnOffGPIO();
}

void Stick::turnOnGPIO()
{
	_gpio.setValue(GPIO_VALUE(_onValue & 1));

	cout << endl << "GPIO [" << _gpio_num << "] is On @ " 
	     << _gpio.getValue()  << endl;	
}

void Stick::turnOffGPIO()
{
	_gpio.setValue(GPIO_VALUE((!_onValue) & 1));

	cout << "GPIO [" << _gpio_num << "] is Off @ " 
	     << _gpio.getValue()  << endl << endl;	
}
