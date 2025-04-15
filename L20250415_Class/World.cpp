
#include "World.h"
#include "Player.h"
#include "Goblin.h"
#include "Boar.h"
#include "Slime.h"
#include <iostream>

UWorld::UWorld()
{
	Initialize();
}

UWorld::~UWorld()
{
	Terminate();
}

void UWorld::Initialize()
{
	srand(time(nullptr));
	Characters.push_back(new APlayer());

	for (int i = 0; i < 10; ++i)
	{
		int Type = rand() % 3;
		if ( Type == 0 )
		{
			Characters.push_back(new ASlime());
		}
		else if (Type == 1)
		{
			Characters.push_back(new AGoblin());
		}
		else if (Type == 2)
		{
			Characters.push_back(new ABoar());
		}
	}

	//for (int i = 0; i < 10; ++i)
	//{
	//	int Type = rand() % 3;
	//	if ( Type == 0 )
	//	{
	//		Slimes.push_back(new ASlime());
	//	}
	//	else if (Type == 1)
	//	{
	//		Goblins.push_back(new AGoblin());
	//	}
	//	else if (Type == 2)
	//	{
	//		Boars.push_back(new ABoar());
	//	}
	//}

	//for (int i = 0; i < 1; ++i)
	//{
	//	Players.push_back(new APlayer());
	//}
}

void UWorld::Terminate()
{
	for (int i = 0; i < Characters.size(); ++i)
	{
		delete Characters[i];
	}
	Characters.clear();

	//for (int i = 0; i < Slimes.size(); ++i)
	//{
	//	delete Slimes[i];
	//}
	//Slimes.clear();

	//for (auto Goblin : Goblins)
	//{
	//	delete Goblin;
	//}
	//Goblins.clear();

	//for (int i = 0; i < Boars.size(); ++i)
	//{
	//	delete Boars[i];
	//}
	//Boars.clear();

	//for (int i = 0; i < Players.size(); ++i)
	//{
	//	delete Players[i];
	//}
	//Players.clear();
}
