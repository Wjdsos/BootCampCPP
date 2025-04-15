#pragma once

#include <vector>

class APlayer;
class ASlime;
class AGoblin;
class ABoar;
class ACharacter;


//World has a Player.

class UWorld
{
public:
	UWorld();
	~UWorld();


	std::vector<ACharacter*> Characters;
	//std::vector<APlayer*> Players;
	//std::vector<AMonster*> Monsters;
	//std::vector<ASlime*> Slimes;
	//std::vector<AGoblin*> Goblins;
	//std::vector<ABoar*> Boars;

public:
	void Initialize();
	void Terminate();

};

