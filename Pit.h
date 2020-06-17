#pragma once
#include "Hazard.h"

class Pit: public Hazard
{
public:

	Pit();
	std::string getName() const;
private:
	std::string HazardName;
protected:
	//
};
