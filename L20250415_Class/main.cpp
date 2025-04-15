#include <iostream>
#include "World.h"
#include "Slime.h"
#include "Monster.h"
#include <vector>

using namespace std;

int main()
{
	UWorld* MyWorld = new UWorld();

	delete MyWorld;
	MyWorld = nullptr;

	//vector<AActor*> AllActors;
	//for (auto Actor : AllActors)
	//{
	//	Actor->Render();
	//}

	return 0;
}