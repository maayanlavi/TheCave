#include "SealedRoom.h"
#include "Hazard.h"
//#include "Room.h"

using namespace std;


SealedRoom::SealedRoom(int tunnel1, int tunnel2, int tunnel3) : Room (tunnel1, tunnel2, tunnel3)
{

}

SealedRoom::SealedRoom(const Room& r): Room (r)
{

}

SealedRoom::~SealedRoom()
{
	delete _hazard;
	
}

bool SealedRoom::attackInRoom(string& message) const
{		
	message = "You just shot yourself";
	return true;
}

bool SealedRoom:: operator== (const Room& other) const
{
	if (!Room::operator==(other))
		return false;

	const SealedRoom* tmp = dynamic_cast<const SealedRoom*>(&other);
	return (_hazard == tmp->_hazard);
	
}


