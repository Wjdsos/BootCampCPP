#include <iostream>
#include "World.h"
#include "Slime.h"
#include <vector>

using namespace std;

int main()
{
	ASlime* Slime = new ASlime;

	cout << Slime->GetHP() << endl;

	return 0;
}