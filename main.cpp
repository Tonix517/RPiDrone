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
   cout << "Please stroke Ctrl-D when controller is booted" << endl;
	me.bootUp();

/*
	unsigned steps = 20;
	float lv = 50.f;
	for(int i = 0; i < steps; i ++)
	{
		float v = 100.f - ((100.f/ steps) * i);

		me.UpDown(v);
		me.ShiftLR(43.f + lv);
		me.FwdBack(43.f + lv);
		//me.TurnLR(v);

		lv = -lv;
		cout << "On " << v << endl;
		usleep(1000000);
	}
*/
	ScriptAgent sa(me);
	sa.Play("./script1.txt");

	getchar();
	return 0;
}
