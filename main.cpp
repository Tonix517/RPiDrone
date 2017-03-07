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

	me.ShiftLR(50.f);
	me.FwdBack(50.f);
	me.TurnLR(50.f);
	
	usleep(2000000);
	unsigned steps = 20;
	for(int i = 0; i < steps; i ++)
	{
		float v = 5.f + 90.f/steps*i; 

		//me.UpDown(100.f - 100.f/steps * i);
		//usleep(1000);
		
		unsigned steps0 = 120;
#if 0
		float v0 = 0.f;
		for(int j = 0; j < steps0; j ++)
		{
			me.FwdBack(50.f + v0);
			v0 += 45.f/steps0 * j * (i % 2?-1:1);
			usleep(10000);
		}
#endif
#if 1
		float v1 = 0.f;
		for(int j = 0; j < steps0; j ++)
		{
			me.TurnLR(50.f + v1);
			v1 += 45.f/steps0 * j * (i % 2?-1:1);
			usleep(10000);
		}
#endif
#if 0
		float v2 = 0.f;
		for(int j = 0; j < steps0; j ++)
		{
			me.ShiftLR(50.f + v2);
			v2 += 45.f/steps0 * j * (i % 2?-1:1);
			usleep(10000);
		}
#endif
		cout << "On " << v << endl;
		usleep(400000);
	}
	ScriptAgent sa(me);
	sa.Play("./script1.txt");

	return 0;
}
