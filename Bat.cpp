//#include "Hazard.h"
#include "Bat.h"
#include <string>

using namespace std;

Bat::Bat():Hazard()
{
	HazardName = "Bat";
}
std::string Bat::getName() const
{
	return "Bat";
}