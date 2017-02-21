#include "Config.h"
#include "Stick.h"

#include <vector>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <math.h>
using namespace std;
using namespace exploringRPi;

bool inputAvailable()  
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return (FD_ISSET(0, &fds));
}

int main()
{
	Stick ud(UPDOWN_GPIO, UPDOWN_MIN, UPDOWN_MAX, UPDOWN_ACTIVE);
	Stick rt(ROTATE_GPIO, ROTATE_MIN, ROTATE_MAX, ROTATE_ACTIVE);
	Stick fb(FB_GPIO, FB_MIN, FB_MAX, FB_ACTIVE);
	Stick lr(LR_GPIO, LR_MIN, LR_MAX, LR_ACTIVE);


   cout << "Please stroke Ctrl-D when controller is booted" << endl;
   float v = 0.0; 
   float s = 0.001;
   while(true)
   {
      float out = sin(v) * 50.0 + 50.0;
      ud.go(out);
      v += s;
      usleep(1000);
	
	if(inputAvailable()) break;
   }

	unsigned steps = 20;
	for(int i = 0; i < steps; i ++)
	{
		float v = 100.f - ((100.f/ steps) * i);
		ud.go(v);
		cout << "On " << v << endl;
		usleep(1000000);
	}
	return 0;
}
