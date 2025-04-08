#include <iostream>

using namespace std;

int main() {
	int Card[] = { 0, };
	int i = 0;
	int Total = 0;
	string deal;

	srand(time(0));

	while(true) 
	{
		cout << "현재 카드: ";
		for(int j; j < i; j++)
		{
			cout << Card[j] << " ";
		}

		cout << endl << "총합: ";
		for (int j; j < i; j++)
		{
			Total += Card[j];
		}

		cout << Total << endl;


		cout << endl << "카드를 받으시겠습니까?(y/n) ";
		cin >> deal;

		if (deal == "y")
		{
			Card[i] = rand() % 11 + 1;
			cout << "받은 카드: " << Card[i] << endl;
		}
		else if (deal == "n")
		{
			cout << endl << "총합: ";
			for (int j; j < i; j++)
			{
				Total += Card[j];
			}

			if (Total > 21)
			{
				cout << "패배!";
			}
			else if (Total == 21)
			{
				cout << "승리!";
			}
			else
			{
				cout << "비김!";
			}
			return 0;
		}
		else
		{
			i--;
		}
		i++;
		Total = 0;
	}
	return 0;
}