#pragma once

#include <vector>

class APlayer;
class ASlime;
class AGoblin;
class ABoar;

//World has a Player.

class UWorld
{
public:
	std::vector<APlayer*> Player;
	std::vector<ASlime*> Slime;
	std::vector<AGoblin*> Goblin;
	std::vector<ABoar*> Boar;

private:
	void Spawn();

public:
	void Initialize();
};

