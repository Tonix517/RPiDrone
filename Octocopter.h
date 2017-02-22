#ifndef OCTOCOPTER_H
#define OCTOCOPTER_H

#include "Stick.h"

class Octocopter
{
	Stick ud;
	Stick rotate;
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

	void Up(float v, unsigned durationMs = 0);
	void Down(float v, unsigned durationMs = 0);

	void TurnL(float v, unsigned durationMs = 0);
	void TurnR(float v, unsigned durationMs = 0);
	void ShiftL(float v, unsigned durationMs = 0);
	void ShiftR(float v, unsigned durationMs = 0);
	void Fwd(float v, unsigned durationMs = 0);
	void Back(float v, unsigned durationMs = 0);

	// util ops
	void Hover();
	void Land();
	
private:
	
	float _calib(float v);
	void _sleepAndOff(unsigned ms, Stick &s, float calibV);
};

#endif
