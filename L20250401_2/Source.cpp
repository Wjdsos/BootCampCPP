#include <iostream>

using namespace std;

int main() 
{
	int Korean[3];
	int English[3];
	int Mathmatic[3];

	int Total[3];
	float Average[3];

	for (int i = 0; i <= 3; i++) 
	{
		cout << i << "��° �л� ����" << endl;

		cout << "����: ";
		cin >> Korean[i];

		cout << "����: ";
		cin >> English[i];

		cout << "����: ";
		cin >> Mathmatic[i];

		Total[i] = Korean[i] + English[i] + Mathmatic[i];
		Average[i] = Total[i] / 3.0f;
	}

	for (int i = 0; i <= 3; i++) 
	{
		cout << i << "��° �л� ���: " << Average[i] << endl;
		
		if(Average[i] >= 90)
		{
			cout << "1����Դϴ�." << endl << endl;
		}
		else if (Average[i] >= 80)
		{
			cout << "2����Դϴ�." << endl << endl;
		}
		else if (Average[i] >= 70)
		{
			cout << "3����Դϴ�." << endl << endl;
		}
		else if (Average[i] >= 60)
		{
			cout << "4����Դϴ�." << endl << endl;
		}
		else
		{
			cout << "5����Դϴ�." << endl << endl;
		}
	}
	return 0;
}