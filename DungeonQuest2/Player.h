#pragma once
#include <string>
#include <vector>

class Player
{
// Create private variables and function definitions
private:
	int m_Health;
	int m_BaseAttack;
	std::vector<std::string> items;
	void ApplyArmor();

// Create public constructor and function definitions for usage in other files
public:
	Player();
	int GetHealth() const;
	int GetAttack() const;
	void AddItem(std::string item);
	void SetHealth(int health);
};

