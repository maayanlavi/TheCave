//#include "Hazard.h"
#include "MushMush.h"
#include <string>

using namespace std;

MushMush::MushMush():Hazard()
{
	HazardName = "MushMush";
}

string MushMush::getName() const
{
	return "MushMush";
}