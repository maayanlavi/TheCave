#pragma once
#include "Hazard.h"

class Bat: public Hazard
{
public:
	Bat();
	std::string getName() const;
private:
	std::string HazardName;

	//
};

