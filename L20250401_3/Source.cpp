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
		cout << "������������ �׾��" << endl << endl;
		cout << "����� �׾����ϴ�!" << endl << endl;
	}

	return 0;
}