#include "pch.h"
#include "monster.h"
#include <iostream>


Monster::Monster()
{
	// Set the attack and health of the monster to random values
	m_Attack = rand() % 25 + 10;
	m_Health = rand() % 50 + 1;

	std::cout << "A monster has appeared with " << m_Health << " health and " << m_Attack << " damage per hit." << std::endl;
}

// Create a function that returns the monsters randomly set attack
int Monster::GetAttack() const
{
	return m_Attack;
}

// Create a function that returns the monsters randomly set health
int Monster::GetHealth() const
{
	return m_Health;
}

// Create a function to manually set the monsters health
void Monster::SetHealth(int health)
{
	// If health is less than or equal to zero, inform the player that they won
	if (health <= 0) 
	{
		m_Health = 0;
		std::cout << "The monster has died!";
	}
	// If not, inform the player of what the remaining health is
	else 
	{
		m_Health = health;
		std::cout << "The monster has " << m_Health << " health left.";
	}
}

// Create a function to manually set the attack of the monster
void Monster::SetAttack(int attack)
{
	m_Attack = attack;
}
