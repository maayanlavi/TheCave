#include "RegularRoom.h"
#include "Hazard.h"
//#include "Room.h"


RegularRoom::RegularRoom(int tunnel1, int tunnel2, int tunnel3) : Room(tunnel1, tunnel2, tunnel3)
{

}

RegularRoom::RegularRoom(const Room& r) : Room(r)
{

}

RegularRoom::~RegularRoom()
{
	delete _hazard;
}


bool RegularRoom:: operator== (const Room& other) const
{
	if (!Room::operator==(other))
		return false;

	const RegularRoom* tmp = dynamic_cast<const RegularRoom*>(&other);
	return (_hazard == tmp->_hazard);

}