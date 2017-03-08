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

	ScriptAgent sa(me);
	sa.Play("./script1.txt");

	return 0;
}
