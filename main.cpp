#include "Config.h"
#include "Octocopter.h"

#include <unistd.h>

#include <vector>
#include <iostream>
using namespace std;
using namespace exploringRPi;

int main()
{

	Octocopter me;
   cout << "Please stroke Ctrl-D when controller is booted" << endl;
	me.bootUp();

me.ShiftL(53.f);

	unsigned steps = 20;
	float lv = 50.f;
	for(int i = 0; i < steps; i ++)
	{
		float v = 100.f - ((100.f/ steps) * i);

		me.Up(v);
		me.ShiftL(53.f + lv);
		me.Fwd(50.f + lv);
		me.TurnL(100.f - v);

		lv = -lv;
		cout << "On " << v << endl;
		usleep(1000000);
	}
	getchar();
	return 0;
}
