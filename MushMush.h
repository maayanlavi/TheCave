#pragma once
#include "Hazard.h"

class MushMush : public Hazard
{
public:
	MushMush();
	std::string getName() const;
private:
	std::string HazardName;
protected:
	//
};
