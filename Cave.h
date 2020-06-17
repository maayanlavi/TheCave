
#include <iostream>
#include <string>
#pragma once

class Room;

class Cave
{
public:
	Cave(const int* sealedRooms, int size);
	~Cave();
	const Room* getRoomAtIndex(int index) const;
	void plotHazard(int idx, const std::string& eventName);
	void plotPlayerIdx(int idx);
	int findMushMush(void) const;
	void movePlayer(int idx);
	std::string playerAttack(int idx);
	std::string playerClash(int idx);
	bool gameOver() const;
	bool checkTunnels(int idx);
	//int getPlayerIdx(int idx);

	void hazardNearPlayer(std::string* hazards) const;

private:
	Room* RoomArr[20];
	int playerIdx;
};
