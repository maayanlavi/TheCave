#include <iostream>
#include "Room.h"
//#include "Hazard.h"
#include "cave.h"
#include "SealedRoom.h"
#include "RegularRoom.h"
#include "Bat.h"
#include "Pit.h"
#include "MushMush.h"
#include <typeinfo>

using namespace std;

Cave::Cave(const int* sealedRooms, int size) 
{
	plotPlayerIdx(playerIdx);
	RoomArr[0] = new Room(2, 18, 19);
	RoomArr[1] = new Room(5, 17, 18);
	RoomArr[2] = new Room(0, 4, 17);
	RoomArr[3] = new Room(7, 16, 19);
	RoomArr[4] = new Room(2, 6, 15);
	RoomArr[5] = new Room(12, 14, 16);
	RoomArr[6] = new Room(4, 13, 17);
	RoomArr[7] = new Room(3, 11, 12);
	RoomArr[8] = new Room(6, 10, 11);
	RoomArr[9] = new Room(5, 10, 13);
	RoomArr[10] = new Room(8, 9, 12);
	RoomArr[11] = new Room(7, 8, 15);
	RoomArr[12] = new Room(7, 10, 14);
	RoomArr[13] = new Room(6, 9, 17);
	RoomArr[14] = new Room(5, 12, 16);
	RoomArr[15] = new Room(4, 11, 19);
	RoomArr[16] = new Room(3, 14, 18);
	RoomArr[17] = new Room(1, 2, 13);
	RoomArr[18] = new Room(0, 1, 16);
	RoomArr[19] = new Room(0, 3, 15);

	for (int i = 0; i < size; ++i)
	{
		//delete (RoomArr[sealedRooms[i]]);
		int tmp = sealedRooms[i];
		RoomArr[tmp] = new SealedRoom(*RoomArr[tmp]);	//copy the room and make him sealed
	}

	for (int i = 0; i < 20; ++i)
	{
		if (typeid(RoomArr[i]) != typeid(SealedRoom))
			RoomArr[i] = new RegularRoom(*RoomArr[i]);
	}
}

	Cave::~Cave()
	{
		
		delete* RoomArr;
	}

	void Cave::plotHazard(int idx, const string& eventName)
	{
		Hazard* p = new Pit();
		Hazard* b = new Bat();
		Hazard* m = new MushMush();

		if (eventName != "MushMush" && eventName != "Pit" && eventName != "Bat")
			throw ("Invalid Hazard Exception");
		if (idx > 19 || idx < 0 || (RoomArr[idx]->getHazard()) != nullptr)
			throw ("Invaild Index Exception");
		else
		{
			if (eventName == "Pit")
				RoomArr[idx]->setHazard(p);
			if (eventName == "Bat")
				RoomArr[idx]->setHazard(b);
			if (eventName == "MushMush")
				RoomArr[idx]->setHazard(m);
		}

	}

	void Cave::plotPlayerIdx(int idx)
	{
		if (idx > 19 || idx < 0 || RoomArr[idx]->getHazard() != nullptr)
			throw "Invalid Index Exception";

		else
		{
			playerIdx = idx;
		}
	}

	int Cave::findMushMush(void) const
	{
		for (int i = 0; i < 20; ++i)
		{
			if (RoomArr[i]->isMushMushHere() == true)
				return i;
		}

		throw ("MushMush Not Found Exception");
	}

	bool Cave::checkTunnels(int idx)
	{
		if ((RoomArr[playerIdx]->getTunnel1() != idx && RoomArr[playerIdx]->getTunnel2() != idx && RoomArr[playerIdx]->getTunnel3() != idx))
			return false;
		return true;
	}
	void Cave::movePlayer(int idx)
	{
		bool res;
		string s;
		
		if (idx > 19 || idx < 0 || checkTunnels(idx)==false)
			throw "Invalid Index Exceptipn";

		else
			playerIdx = idx;

		if (typeid(*RoomArr[playerIdx]->getHazard()) == typeid(MushMush) || typeid(*RoomArr[playerIdx]->getHazard()) == typeid(Pit))
		{
			res = RoomArr[playerIdx]->clashInRoom(s);
			//count << s << endl;
			if (!res)
				res = gameOver();
		}

		if (typeid(*RoomArr[idx]->getHazard()) == typeid(Bat))
		{
			res = RoomArr[idx]->clashInRoom(s);
			//count << s << endl;
			playerIdx = 19; // לאן העטלף מעביר אותו??
			RoomArr[idx]->setHazard(nullptr);
			
		}

	}

	string Cave::playerAttack(int idx)
	{
		if (checkTunnels(idx) == false) {
			throw "Invalid Index Exceptipn";
			return " ";
		}
		

		else {

			string s = RoomArr[idx]->roomHazard();
			bool result = RoomArr[idx]->attackInRoom(s);
			Hazard* m = new MushMush();

				if (!result) {
				int MushMushIdX = findMushMush();

				int t1 = RoomArr[MushMushIdX]->getTunnel1();
				int t2 = RoomArr[MushMushIdX]->getTunnel2();
				int t3 = RoomArr[MushMushIdX]->getTunnel3();
				int arr[3] = { t1, t2, t3 };

				for (int i = 0; i < 3; ++i)
				{
					if (RoomArr[arr[i]]->getHazard() == nullptr)
					{
						RoomArr[arr[i]]->setHazard(m);
						return s;
					}
				}
					return s;
				
			}
		}
	
	}

	bool Cave::gameOver() const
	{
		return true;
	}

	void Cave::hazardNearPlayer(string* hazards) const
	{
		hazards[0]=RoomArr[RoomArr[playerIdx]->getTunnel1()]->roomHazard();
		hazards[1] = RoomArr[RoomArr[playerIdx]->getTunnel2()]->roomHazard();
		hazards[2] = RoomArr[RoomArr[playerIdx]->getTunnel3()]->roomHazard();
	}

	const Room* Cave::getRoomAtIndex(int index) const
	{
		if (index>19 || index<0)
			throw "Invalid Index Exceptipn";
		else
			return RoomArr[index];
	}

	 std::string Cave::playerClash(int idx)
	{
		playerIdx = idx;
		string msg;
		if (RoomArr[playerIdx]->clashInRoom(msg))
			return msg;
		if (typeid(*RoomArr[playerIdx]->getHazard())==typeid(Bat))
			return playerClash(3);
	}
