#include "pch.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

Player::Player()
{
	// Set base health and attack of the player
	m_Health = 100;
	m_BaseAttack = 20;

	// Set the initial size of the items vector to the amount of loot
	items.reserve(5);
}

/*
	Create a function that returns the amount of health the player has
*/
int Player::GetHealth() const
{
	return m_Health;
}

/*
	Create a function that returns the attack of the player
	Attack is equal to the base damage plus the upgrades
	Intentionally chooses the Axe over the Sword if the player has both
*/
int Player::GetAttack() const
{
	int attack = m_BaseAttack;
	if (std::find(items.begin(), items.end(), "axe") != items.end()) 
	{
		attack += 30;
	}
	else if (std::find(items.begin(), items.end(), "sword") != items.end()) 
	{
		attack += 20;
	}

	return attack;
}

/*
	Create a function that adds the specified item to the items list
	Used for the player to obtain loot
*/
void Player::AddItem(std::string item)
{
	items.push_back(item);
}

/*
	Create a function that manages the health of the player
*/
void Player::SetHealth(int health)
{
	// Call the ApplyArmor function to pad damage
	ApplyArmor();

	// If health is less than or equal to zero inform the player that they lose
	if (health <= 0)
	{
		m_Health = 0;
		std::cout << "You have been defeated. Game Over!" << std::endl;
	}
	else
	{
		// Create temp variables to account for the shield and armor
		int temp = m_Health;
		int temp2 = 100 - health;
		
		m_Health = temp - temp2;
		
		// If armor still lasting, remove it till next fight
		if (m_Health > 100)
		{
			m_Health = 100;
		}

		std::cout << "You have " << m_Health << " life left." << std::endl;
	}
}

/*
	Create a function that applies the necessary amount of shielding based on the loot the player has
*/
void Player::ApplyArmor()
{
	if (std::find(items.begin(), items.end(), "armor") != items.end())
	{
		m_Health += 30;
	}

	if (std::find(items.begin(), items.end(), "shield") != items.end())
	{
		m_Health += 20;
	}
}


