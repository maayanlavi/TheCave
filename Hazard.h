#pragma once
#include <string>
//#include "Pit.h"
//#include "Bat.h"
//#include "MushMush.h"

using namespace std;
#pragma pack(push, 1)
class Hazard
{
public:
	
	//Hazard() {};
	Hazard() { };
	virtual ~Hazard() {};
	virtual std::string getName() const = 0;
	const Hazard& operator= (const Hazard& other) { HazardName = other.HazardName; }
		
protected:
	
	std::string HazardName;
	
};

#pragma pack(pop)
