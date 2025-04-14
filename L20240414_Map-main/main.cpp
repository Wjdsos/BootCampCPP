#include <iostream>

using namespace std;

int main()
{
	int data[3] = { 100, 200, 300 };

	int* ptr = data;

	cout << "data[0]: " << *ptr << endl;
	cout << "data[1]: " << *(ptr + 1) << endl;
	cout << "data[2]: " << *(ptr + 2) << endl;
}