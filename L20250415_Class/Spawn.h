#pragma once
#include "Monster.h"
#include <stdlib.h>

class ASpawn : public AMonster
{
public: // �������� ���� ����
	int RandomNumber = rand() % 10 + 1;

	void SpawnGoblin()
	{
		
	};
	void SpawnBoar()
	{

	};
	void SpawnSlime()
	{

	};
};

