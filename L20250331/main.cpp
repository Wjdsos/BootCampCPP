#include <iostream>

// ���� C������ �ҹ��ڷ� �Ǿ� ����
using namespace std;

enum EColor {
	Red = 0,
};

int main() {

	EColor Color = EColor::Red;
	int Num1 = 100;
	int Num2 = 15;
	cout << Num1 + Num2 << endl;

	float Num3 = (float)Num1 / (float)Num2;
	cout << Num3 << endl;


	//����ȯ,Casting
	float A = 5.5f;
	int B = static_cast<int>(A);

	return 0;
}