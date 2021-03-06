// DungeonQuest2.cpp

#include "pch.h"
#include <iostream>
#include <ctime>
#include "Dungeon.h"

int main()
{
	// Create the player and dungeon objects for the game
	Player player;
	Dungeon dungeon;

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	// Get the players name
	std::string name;
	std::cout << "What is your name adventurer?: ";
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Well " << name << ", let me set the scene for you." << std::endl;

	// print intro
	std::cout << "You have woken up in a dungeon and must defeat the big bad boss to escape." << std::endl;
	std::cout << "You have to make it through " << dungeon.GetRoomsLeft() << " rooms crawling with monsters\nin order to get to the boss." << std::endl;
	std::cout << "Along the way you will pick up loot to help you in your journey. " << std::endl;
	
	std::cout << "Here is the list:" << std::endl;
	std::cout << "Sword - +20 attack damage to monsters (replaces current weapon if worse)" << std::endl;
	std::cout << "Axe - +30 attack damage to monsters (replaces current weapon if worse)" << std::endl;
	std::cout << "Armor - +50 damage resistance (take 50 less damage from hits)" << std::endl;
	std::cout << "Shield - +25 damage resistance (take 25 less damage from hits)" << std::endl;
	std::cout << "Torch - 25% less chance of being encountered by a monster" << std::endl;
	std::cout << "You are armed with fists at the moment and have 100 health, good luck!" << std::endl;

	while (player.GetHealth() > 0 && dungeon.GetRoomsLeft() > 0)
	{
		std::cout << "Your current health is: " << player.GetHealth() << std::endl;
		std::cout << "Rooms left to go through: " << dungeon.GetRoomsLeft() << std::endl;
		std::cout << "You can rest (gain +15 health) or move to the next room." << std::endl;
		std::cout << "What do you choose? Type rest or move" << std::endl;

		// create a variable to store the player choice
		std::string choice;
		std::cin >> choice;


		// if the player chose to rest, restore 15 health
		if (choice == "rest")
		{
			player.SetHealth(player.GetHealth() + 15);
			continue;
		}

		// if the player chose to move, decrement the amount of rooms to go
		else if (choice == "move")
		{
			dungeon.SetRoomsLeft(dungeon.GetRoomsLeft() - 1);
		}

		if (dungeon.MonsterAppeared()) 
		{
			// Instantiate a monster object, create pointers to the objects
			Monster monster;
			Player* pPlayer = &player;
			Monster* pMonster = &monster;

			// Loop until the fighting is over
			while (true) 
			{
				std::string result = dungeon.SimulateFight(pMonster, pPlayer);

				// if the result is victory, inform the player of their success
				if (result == "victory")
				{
					std::cout << "The monster was defending a loot chest! Opening it..." << std::endl;

					std::string loot = dungeon.RollLoot();
					std::cout << loot << " aquired!" << std::endl;

					player.AddItem(loot);

					break;
				}
				// if the result is defeat, inform the player it is game over
				else if (result == "defeat")
				{
					break;
				}
				// if the result is ongoing, inform the player it is their turn again
				else if (result == "ongoing")
				{
					std::cout << "Your turn again!" << std::endl;
				}
			}
		}
		
		// If there are no more dungeon rooms to go through then start the boss fight
		if (dungeon.GetRoomsLeft() == 0) 
		{
			std::cout << "No dungeon rooms left. Fighting the boss!" << std::endl;

			// Create the boss object and a pointer to the boss and player
			Monster boss;
			Player* pPlayer = &player;
			Monster* pBoss = &boss;

			// Set the boss stats
			boss.SetHealth(200);
			boss.SetAttack(100);

			std::cout << "Boss health set to 200" << std::endl;
			std::cout << "Boss attack set to 100" << std::endl;

			std::cout << "The room is filled with the bones of other adventureres. Gold surrounds the place, clearly this boss\nhas been here a very long time and no one has defeated him before... Good luck!" << std::endl;
			
			// Loop until fighting ends
			while (true)
			{
				std::string result = dungeon.SimulateFight(pBoss, pPlayer);

				// if the result is victory, inform the player of their success
				if (result == "victory")
				{
					std::cout << "You have beaten the game. Congratz!" << std::endl;

					break;
				}
				// if the result is defeat, inform the player it is game over
				else if (result == "defeat")
				{
					break;
				}
				// if the result is ongoing, inform the player it is their turn again
				else if (result == "ongoing")
				{
					std::cout << "Your turn again!" << std::endl;
				}
			}
		}
	}
}
