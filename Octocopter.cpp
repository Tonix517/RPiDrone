#include "Octocopter.h"
#include "Config.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <math.h>

#include <algorithm>

using namespace std;
using namespace exploringRPi;

Octocopter::Octocopter():
	ud(UPDOWN_GPIO, UPDOWN_ACTIVE),
	rt(ROTATE_GPIO, ROTATE_ACTIVE),
	fb(FB_GPIO, FB_ACTIVE),
	lr(LR_GPIO, LR_ACTIVE),
	calib_ud(0.f),
	calib_rot(0.f),
	calib_lr(0.f),
	calib_fb(0.f)
{

}

Octocopter::~Octocopter()
{}

void Octocopter::bootUp()
{
	// All other sticks go to ZERO
	lr.go(70.f);
	rt.go(50.f);
	fb.go(50.f);

	unsigned steps = 20;
	for(int i = 0; i < steps; i ++)
	{
		ud.setVal(100.f - 100.f/steps * i);
		usleep(20000);
	}	

	ud.go(100.f);
	// Start from level 0 after bootup
	//ud.setVal(100.f);
	//usleep(20000);
}

void Octocopter::applySignalCalib(float cud, float crot, float clr, float cfb)
{
	calib_ud = cud;
	calib_rot= crot;
	calib_lr = clr;
	calib_fb = cfb;
}

float Octocopter::_calib(float v)
{
	return min(max(0.f, v), 100.f);
}

void Octocopter::_sleepAndOff(unsigned ms, Stick &s, float calibV)
{
	if(ms > 0)
	{
		usleep(ms * 1000);
		s.go(calibV);
	}
} 

void Octocopter::UpDown(float v, unsigned durationMs)
{
	v = _calib(v + calib_ud);
	ud.go(v);
	_sleepAndOff(durationMs, ud, calib_ud);
}

void Octocopter::ShiftLR(float v, unsigned durationMs)
{
	v = _calib(v + calib_lr);
	lr.go(v);
	_sleepAndOff(durationMs, lr, calib_lr);
}

void Octocopter::FwdBack(float v, unsigned durationMs)
{
	v = _calib(v + calib_fb);
	fb.go(v);
	_sleepAndOff(durationMs, fb, calib_fb);
}

void Octocopter::TurnLR(float v, unsigned durationMs)
{
	v = _calib(v + calib_rot);
	rt.go(v);
	_sleepAndOff(durationMs, rt, calib_rot);
}

void Octocopter::Hover()
{

}

void Octocopter::Land()
{

}

