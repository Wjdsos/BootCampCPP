#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
	void Attack();
	void Die();

	inline int GetHP() 
	{
		return HP;
	}

	inline void SetHP(int Value)
	{
		HP = Value;
	}

protected:
	int HP;
	int Gold;

	void Drop();
};

