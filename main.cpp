#include "Stick.h"

#include <unistd.h>
using namespace std;
using namespace exploringRPi;

int main()
{
	// 23 - LOW
	// 24 - LOW
	// 25 - HIGH
	// 12 - HIGH
	Stick ud(12, 0.f, 100.f, HIGH);
	usleep(2000000);
	
	// Boot-up
	ud.go(100.f);
	usleep(2000000);

	ud.go(75.f);
	usleep(2000000);

	ud.go(0.f);
	
	return 0;
}
