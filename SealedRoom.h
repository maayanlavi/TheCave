
#include "Room.h"
#include <string>
#pragma once

using namespace std;

class SealedRoom : public Room
{
	//Room Sealed;
public:
	SealedRoom(int tunnel1, int tunnel2, int tunnel3);
	SealedRoom(const Room& r);
	virtual ~SealedRoom();
	virtual	bool attackInRoom(string& message) const;
	virtual bool operator== (const Room& other) const;

	

};
