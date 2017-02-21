#ifndef SCRIPT_AGENT_H
#define SCRIPT_AGENT_H

#include "Stick.h"

#include <fstream>

class ScriptAgent
{
	Stick	&ud;
	Stick	&lr;
	Stick	&fb;
	Stick	&turn;
	
	bool	_bReturn; // Do you want Drone to be back to origin
	std::ifstream _in;

public:
	ScriptAgent(const char *fPath,
		    Stick &rud, Stick &rlr, Stick &rfb, Stick &rTurn);
	virtual ~ScriptAgent();

	void Play(bool bReturn);	
};

#endif
