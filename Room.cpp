#include "Room.h"
#include "Hazard.h"
#include "MushMush.h"
#include "Bat.h"
#include "Pit.h"
#include <typeinfo>
#include <string>

using namespace std;


Room::Room(int tunnel1, int tunnel2, int tunnel3)
{
	_tunnels[0] = tunnel1;
	_tunnels[1] = tunnel2;
	_tunnels[2] = tunnel3;

	_hazard = nullptr;
}

Room::Room(const Room& r)
{
	_tunnels[getTunnel1()] =r._tunnels[getTunnel1()];
	_tunnels[getTunnel2()] = r._tunnels[getTunnel2()];
	_tunnels[getTunnel3()] = r._tunnels[getTunnel3()];
	_hazard = r._hazard;
}

Room::~Room()
{
	delete _hazard;
}

int Room::getTunnel1() const
{
	int min = 0;
	int minIndex=0;
	for (int i = 0; i < 3; ++i)
	{
		if (_tunnels[i] < min)
		{
			min = _tunnels[i];
			minIndex = i;
		}
	}

	return minIndex;
}

int Room::getTunnel3() const
{
	int max = 0;
	int maxIndex=0;
	for (int i = 0; i < 3; ++i)
	{
		if (_tunnels[i] > max)
		{
			max = _tunnels[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

int Room::getTunnel2() const
{
	int midIndex=0;

	for (int i = 0; i < 3; ++i)
	{
		if (i != getTunnel1() && i != getTunnel3())
			midIndex=i;
	}

	return midIndex;
}

void Room::setTunnel1(int tunnel1)
{
	_tunnels[1] = tunnel1;
}

void Room::setTunnel2(int tunnel2)
{
	_tunnels[2] = tunnel2;
}

void Room::setTunnel3(int tunnel3)
{
	_tunnels[2] = tunnel3;
}

string Room::roomHazard() const
{

	const string Bat = "Bat is near";
	const string Pit = "Pit is near";
	const string MushMush = "MushMush is near";
	const string empty = " ";
	
	if (typeid(*_hazard)==typeid(Bat))
		return Bat;
	if (typeid(*_hazard) == typeid(Pit))
		return Pit;
	if (typeid(*_hazard) == typeid(MushMush))
		return MushMush;
	
	return empty;
}

bool Room::roomIsEmpty() const
{
	if (_hazard)
		return false;
	return true;
}


bool Room::attackInRoom(string& message) const
{
	if (message == "Bat is near")
	{
		message = "Bat is laughing";
		return false;
	}

	if (message == "Pit is near")
	{
		message = "Pit is whistling";
		return false;
	}

	if (message == "MushMush is near")
	{
		message = "You got MushMush";
		return true;
	}

		message = " ";
		return false;


}
bool Room::clashInRoom(string& msg) const
{
	if (msg == "Bat is near")
	{
		msg = "A Bat will move you";
		return false;
	}

	if (msg == "Pit is near")
	{
		msg = "you fell into Pit";
		return false;
	}

	if (msg== "MushMush is near")
	{
		msg = "MushMush got you";
		return false;
	}


		msg = " ";
		return true;

	
}

bool Room::isMushMushHere() const
{
	if (typeid(*_hazard)==typeid(MushMush))
	//if (_hazard->getName() == "MushMush")
		return true;
	return false;
}

const Hazard* Room::getHazard() const
{
	return _hazard;
}

void Room::setHazard(Hazard* newHazard)
{
	if (typeid(*newHazard) == typeid(MushMush))
		_hazard = new MushMush();
	if (typeid(*newHazard) == typeid(Pit))
		_hazard = new Pit();
	if (typeid(*newHazard) == typeid(Bat))
		_hazard = new Bat();

}

bool Room:: operator== (const Room& other) const
{
	if (getTunnel1() == other.getTunnel1() && getTunnel2() == other.getTunnel2() && getTunnel3() == other.getTunnel3() )
		return true;
	return false;
}

