#include "Config.h"
#include "Octocopter.h"
#include "ScriptAgent.h"

#include <unistd.h>

#include <vector>
#include <iostream>
using namespace std;
using namespace exploringRPi;

int main()
{

	Octocopter me;
	me.bootUp();
	cout << "Octocopter Booted. Ready for Command" << endl;

	unsigned steps = 20;
	float lv = 50.f;
	for(int i = 0; i < steps; i ++)
	{
		float v = 100.f - ((100.f/ steps) * i);

		me.UpDown(max(50.f,v));
		me.ShiftLR(75.f);
		me.FwdBack(40.f);
		//me.TurnLR(v);

		lv = -lv;
		cout << "On " << v << endl;
		usleep(1000000);
	}
	ScriptAgent sa(me);
	sa.Play("./script1.txt");

	return 0;
}
