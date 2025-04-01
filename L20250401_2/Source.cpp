#include <iostream>

using namespace std;

int main() 
{
	int Korean[10];
	int English[10];
	int Mathmatic[10];

	int Total[10];
	float Average[10];

	for (int i = 0; i < 3; i++) 
	{
		cout << i << " Korean: ";
		cin >> Korean[i];
		cout << i << "English: ";
		cin >> English[i];
		cout << i << "Mathmatic: ";
		cin >> Mathmatic[i];

		Total[i] = Korean[i] + English[i] + Mathmatic[i];
		Average[i] = Total[i] / 3.0f;
	}

	for (int i = 0; i < 3; i++) {cout << i << " Average: " << Average[i] << endl;}
	
	return 0;
}