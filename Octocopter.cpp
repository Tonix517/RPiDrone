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
	ud(UPDOWN_GPIO, UPDOWN_MIN, UPDOWN_MAX, UPDOWN_ACTIVE),
	rotate(ROTATE_GPIO, ROTATE_MIN, ROTATE_MAX, ROTATE_ACTIVE),
	lr(FB_GPIO, FB_MIN, FB_MAX, FB_ACTIVE),
	fb(LR_GPIO, LR_MIN, LR_MAX, LR_ACTIVE),
	calib_ud(0.f),
	calib_rot(0.f),
	calib_lr(0.f),
	calib_fb(0.f)
{

}

Octocopter::~Octocopter()
{}

bool inputAvailable()
{
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec= 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
	return FD_ISSET(0, &fds);
}

void Octocopter::bootUp()
{
	float v = 0.f;
	float s = 0.002;
	while(true)
	{
		ud.go(sin(v) * 50.f + 50.f);
		v += s;
		usleep(1000);
		
		if(inputAvailable()) break;
	}

	// Apply Calibrated signals
	lr.go(_calib(calib_lr));
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

void Octocopter::Up(float v, unsigned durationMs)
{
	v = _calib(v + calib_ud);
	ud.go(v);
	_sleepAndOff(durationMs, ud, calib_ud);
}

void Octocopter::Down(float v, unsigned durationMs)
{
	v = _calib(v + calib_ud);
	ud.go(v);
	_sleepAndOff(durationMs, ud, calib_ud);
}

void Octocopter::ShiftL(float v, unsigned durationMs)
{
	v = _calib(v + calib_lr);
	lr.go(v);
	_sleepAndOff(durationMs, lr, calib_lr);
}

void Octocopter::ShiftR(float v, unsigned durationMs)
{
	v = _calib(v + calib_lr);
	lr.go(v);
	_sleepAndOff(durationMs, lr, calib_lr);
}

void Octocopter::Fwd(float v, unsigned durationMs)
{
	v = _calib(v + calib_fb);
	fb.go(v);
	_sleepAndOff(durationMs, fb, calib_fb);
}

void Octocopter::Back(float v, unsigned durationMs)
{
	v = _calib(v + calib_fb);
	fb.go(v);
	_sleepAndOff(durationMs, fb, calib_fb);
}

void Octocopter::TurnL(float v, unsigned durationMs)
{
	v = _calib(v + calib_rot);
	rotate.go(v);
	_sleepAndOff(durationMs, rotate, calib_rot);
}

void Octocopter::TurnR(float v, unsigned durationMs)
{
	v = _calib(v + calib_rot);
	rotate.go(v);
	_sleepAndOff(durationMs, rotate, calib_rot);
}


void Octocopter::Hover()
{

}

void Octocopter::Land()
{

}

