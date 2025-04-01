#include <iostream>

using namespace std;

int main() 
{
	float Color = 0;
	int Apple = 0;
	int Goblin = 0;
	char Alphabet = 'A';
	bool Condition = true;
	bool IsFinish = false;
	bool IsRunning = true;

	char key = 0;


	for (; IsRunning;)
	{
		cin >> key;
		if (key == 'q')
		{
			IsRunning = false;
		}
		cout << "느려터졌구나 죽어라" << endl << endl;
		cout << "당신은 죽었습니다!" << endl << endl;
	}

	return 0;
}