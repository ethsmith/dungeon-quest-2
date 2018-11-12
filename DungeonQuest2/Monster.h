#pragma once
class Monster
{
// Create private variables
private:
	int m_Attack;
	int m_Health;

// Create public constructor and function definitions for usage in other files
public:
	Monster();
	int GetAttack() const;
	int GetHealth() const;
	void SetHealth(int health);
	void SetAttack(int attack);
};


