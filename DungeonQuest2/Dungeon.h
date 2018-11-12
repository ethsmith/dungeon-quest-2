#pragma once
#include <vector>
#include <string>
#include "monster.h"
#include "Player.h"

class Dungeon
{
// Create private variables and function definitions
private:
	int m_Rooms;
	std::vector<std::string> loot;

// Create public constructor and function definitions for usage in other files
public:
	Dungeon();
	int GetRoomsLeft() const;
	bool MonsterAppeared();
	std::string SimulateFight(Monster* monster, Player* player);
	std::string RollLoot();
	void SetRoomsLeft(int rooms);
};