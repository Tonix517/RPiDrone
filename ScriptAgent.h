#ifndef SCRIPT_AGENT_H
#define SCRIPT_AGENT_H

#include "Octocopter.h"

class ScriptAgent
{

	Octocopter &me;
	
public:
	ScriptAgent(Octocopter &r); 
	virtual ~ScriptAgent();

	void Play(const char* fPath);

private:
	void _ProcCmd(const string &cmd);
};

#endif
