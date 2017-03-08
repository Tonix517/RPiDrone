#include "ScriptAgent.h"

#include <unistd.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace exploringRPi;

ScriptAgent::ScriptAgent(Octocopter &r):me(r)
{}

ScriptAgent::~ScriptAgent()
{}

void ScriptAgent::Play(const char *fPath)
{
	ifstream f(fPath);
	if (!f.is_open())
	{
    		cout << "error while opening file" << endl;
		return;
	}
	string line;
	while(getline(f, line)) 
	{
    		_ProcCmd(line);
    	}
	if (f.bad())
	{
    		cout << "error while reading file" << endl;
	}
}

void ScriptAgent::_ProcCmd(const string &cmdStr)
{
	istringstream stream(cmdStr);

	string cmd; float v = 0.f;
	stream >> cmd >> v;

	if (cmd[0] == '#') return;

	if(cmd == "LR")
	{
		cout << "Left|Right " << v  << endl;
		me.ShiftLR(v);
	}
	else if(cmd == "UD")
	{
		cout << "Up|Down " << v <<  endl;
		me.UpDown(v);
	}
	else if(cmd == "FB")
	{
		cout << "Forward|Back " << v << endl;
		me.FwdBack(v);
	}
	else if(cmd == "RT")
	{
		cout << "Rotate " << v <<  endl;
		me.TurnLR(v);
	}
	else if(cmd == "SLEEP")
	{
		cout << "Sleep " << v << endl;
		usleep((unsigned)v);
	}
}
