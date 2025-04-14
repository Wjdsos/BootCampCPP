#include <iostream>
#include "Player.h"
#include "Floor.h"
#include "Goal.h"
#include "Monster.h"
#include "Wall.h"
#include "World.h"

using namespace std;

int main()
{
	APlayer* Player = new APlayer;

	delete Player;
	Player = nullptr;

	return 0;
}