#ifndef OCTOCOPTER_H
#define OCTOCOPTER_H

#include "Stick.h"

class Octocopter
{
	Stick ud;
	Stick rt;
	Stick lr;
	Stick fb;

	// Hardware signal calibration
	float calib_ud;
	float calib_rot;
	float calib_lr;
	float calib_fb;

public:

	Octocopter();
	virtual ~Octocopter();

	void bootUp();

	void applySignalCalib(float cud, float crot, float clr, float cfb);	

	void UpDown(float v, unsigned durationMs = 0);
	void TurnLR(float v, unsigned durationMs = 0);
	void ShiftLR(float v, unsigned durationMs = 0);
	void FwdBack(float v, unsigned durationMs = 0);

	// util ops
	void Hover();
	void Land();
	
private:
	
	float _calib(float v);
	void _sleepAndOff(unsigned ms, Stick &s, float calibV);
};

#endif
