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
	for(int i = 0; i < steps; i ++)
	{
		
#if 1
		me.FwdBack(50.f + i % 2 ? -45.f : 45.f);
#endif
#if 0
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
		usleep(400000);
	}
	ScriptAgent sa(me);
	sa.Play("./script1.txt");

	return 0;
}
