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
		cout << "���� ī��: ";
		for(int j; j < i; j++)
		{
			cout << Card[j] << " ";
		}

		cout << endl << "����: ";
		for (int j; j < i; j++)
		{
			Total += Card[j];
		}

		cout << Total << endl;


		cout << endl << "ī�带 �����ðڽ��ϱ�?(y/n) ";
		cin >> deal;

		if (deal == "y")
		{
			Card[i] = rand() % 11 + 1;
			cout << "���� ī��: " << Card[i] << endl;
		}
		else if (deal == "n")
		{
			cout << endl << "����: ";
			for (int j; j < i; j++)
			{
				Total += Card[j];
			}

			if (Total > 21)
			{
				cout << "�й�!";
			}
			else if (Total == 21)
			{
				cout << "�¸�!";
			}
			else
			{
				cout << "���!";
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