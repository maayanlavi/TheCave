//#include "Hazard.h"
#include "Pit.h"
#include <string>

using namespace std;

Pit::Pit():Hazard()
{
	HazardName = "Pit";
}
std::string Pit::getName() const
{
	return "Pit";
}