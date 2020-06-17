
#include "Room.h"
#include "Hazard.h"
#pragma once

class RegularRoom: public Room
{
public:
	RegularRoom(int tunnel1, int tunnel2, int tunnel3);
	RegularRoom(const Room& r);
	virtual ~RegularRoom();
	//virtual bool attackInRoom(std::string& message) const;
	virtual bool operator== (const Room& other) const;

//protected:
	
};
