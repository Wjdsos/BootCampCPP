#pragma once
#include "Monster.h"
#include <stdlib.h>

class ASpawn : public AMonster
{
public: // 랜덤으로 몬스터 스폰
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

