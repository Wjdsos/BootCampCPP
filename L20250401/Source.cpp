#include <iostream>

using namespace std;

int main()
{
	int width;

	cout << "길이 입력 ㄱ: ";
	cin >> width;

	// 별 역순으로 출력
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = width; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	/* 
	// 크리스마스 트리 만들기
	for (int i = 1; i < width; i++)
	{
		for (int j = width; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		for (int j = 1; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	*/

	return 0;
}