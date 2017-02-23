#include "ScriptAgent.h"

#include <string>
#include <iostream>
#include <fstream>
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

void ScriptAgent::_ProcCmd(const string &cmd)
{
	cout << cmd << endl;
}
