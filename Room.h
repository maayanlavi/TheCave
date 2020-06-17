#pragma once
#include <string>
#include "cave.h"

using namespace std;

class Hazard;

#pragma pack(push, 1)
class Room
{
public:
	Room(int tunnel1, int tunnel2, int tunnel3);
	Room(const Room& r); //copt c'tor
	virtual ~Room();
	virtual	bool attackInRoom(string& message) const; 
	int getTunnel1() const;
	int getTunnel2() const;
	int getTunnel3() const;
	void setTunnel1(int tunnel1);
	void setTunnel2(int tunnel2);
	void setTunnel3(int tunnel3);
	string roomHazard() const;
	const Hazard* getHazard() const;
	void setHazard(Hazard* newHazard);
	virtual bool operator== (const Room& other) const;
	bool roomIsEmpty() const;
	bool isMushMushHere() const;
	bool clashInRoom(string& msg) const;
protected:
	const Hazard* _hazard;
private:
	int _tunnels[3];
};
#pragma pack(pop)