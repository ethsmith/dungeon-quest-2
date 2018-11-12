#include "pch.h"
#include "Dungeon.h"
#include <iostream>


Dungeon::Dungeon()
{
	// Set initial rooms to 5
	m_Rooms = 5;

	// Add loot that can be acquired
	loot.push_back("sword");
	loot.push_back("axe");
	loot.push_back("armor");
	loot.push_back("shield");
	loot.push_back("torch");
}

/*
	Return the amount of rooms left before the boss
*/
int Dungeon::GetRoomsLeft() const
{
	return m_Rooms;
}

/*
	Create a function that has a 75% of a monster appearing
*/
bool Dungeon::MonsterAppeared()
{
	int appeared = rand() % 4 + 1;
	return appeared > 1;
}

/*
	Simulate monster and player fight
*/
std::string Dungeon::SimulateFight(Monster* monster, Player* player)
{
	std::cout << "You hit the monster with your dagger for " << player->GetAttack()<< " damage." << std::endl;
	// deal damage equal to the players base damage to the monster 
	monster->SetHealth(monster->GetHealth() - player->GetAttack());

	// if the monster dies, return victory
	if (monster->GetHealth() == 0)
	{
		return "victory";
	}

	std::cout << "The monster hits you for " << monster->GetAttack() << " damage." << std::endl;
	// deal damage to the player equal to the monsters randomly generated attack
	player->SetHealth(player->GetHealth() - monster->GetAttack());

	// if the player dies, return defeat
	if (player->GetHealth() == 0)
	{
		return "defeat";
	}

	// return ongoing to continue the fight
	return "ongoing";
}

/*
	Create function that randomly chooses which piece of loot the player gets
	Once a piece of loot has been chosen then it is removed from the possible loot list
	To prevent duplicate loot items.
*/
std::string Dungeon::RollLoot()
{
	int randIndex = rand() % (loot.size() - 1);
	std::string lootRolled = loot.at(randIndex);

	loot.erase(loot.begin() + randIndex);

	return lootRolled;
}

/*
	Create function to set the amount of rooms before the boss
*/
void Dungeon::SetRoomsLeft(int rooms)
{
	m_Rooms = rooms;
}
