#include <iostream>

using namespace std;

int main()
{
	int Goblin[50];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 20; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << "■";
		}
		cout << endl;
	}
	return 0;
}