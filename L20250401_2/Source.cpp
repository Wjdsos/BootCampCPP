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
		cout << i << "번째 학생 성적" << endl;

		cout << "국어: ";
		cin >> Korean[i];

		cout << "영어: ";
		cin >> English[i];

		cout << "수학: ";
		cin >> Mathmatic[i];

		Total[i] = Korean[i] + English[i] + Mathmatic[i];
		Average[i] = Total[i] / 3.0f;
	}

	for (int i = 0; i <= 3; i++) 
	{
		cout << i << "번째 학생 평균: " << Average[i] << endl;
		
		if(Average[i] >= 90)
		{
			cout << "1등급입니다." << endl << endl;
		}
		else if (Average[i] >= 80)
		{
			cout << "2등급입니다." << endl << endl;
		}
		else if (Average[i] >= 70)
		{
			cout << "3등급입니다." << endl << endl;
		}
		else if (Average[i] >= 60)
		{
			cout << "4등급입니다." << endl << endl;
		}
		else
		{
			cout << "5등급입니다." << endl << endl;
		}
	}
	return 0;
}