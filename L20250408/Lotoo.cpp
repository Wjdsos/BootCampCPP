#include <iostream>

// �ζ� ��ȣ ��÷��

int main()
{
	int lotto[6] = {};

	srand(time(0));

	for (int i = 0; i < 6; i++)
	{

		int LottoNumber = rand() % 45 + 1;

		for (int j = 0; j < i; j++)
		{
			if (lotto[j] == LottoNumber)
			{
				i--;
				break;
			}
		}
		lotto[i] = LottoNumber;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (lotto[i] > lotto[j])
			{
				int Temp = lotto[i];
				lotto[i] = lotto[j];
				lotto[j] = Temp;
			}
		}
	}

	std::cout << "��÷ ��ȣ: ";
	for (int i = 0; i < 6; i++)
	{
		std::cout << lotto[i] << ", ";
	}

	return 0;
}