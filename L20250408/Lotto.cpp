#include <iostream>

using namespace std;

// DynamicArray[10]�� DynamicArray[20]���� �ø��� [10]~[19]���� 4�� ��� �ֱ�

void Swap(){}

int main()
{
    int* DynamicArray = new int[10];

    for (int i = 0; i < 10; i++)
    {
        DynamicArray[i] = (i + 1) * 3;
    }

    int* NewDynamicArray = new int[20];

    for (int i = 0; i < 10; i++)
    {
        NewDynamicArray[i] = DynamicArray[i];
    }

    delete[] DynamicArray;
    // or DynamicArray = nullptr;

    for (int i = 10; i < 20; i++)
    {
        NewDynamicArray[i] = (i - 9) * 4;
    }

    for (int i = 0; i < 20; i++)
    {
        cout << NewDynamicArray[i] << " ";
    }

    delete[] NewDynamicArray;
}


/*
int main()
{
    int* DynamicArray = new int[10]; // ���� �迭 ����

    for (int i = 0; i < 10; i++)
    {
        DynamicArray[i] = (i + 1) * 3; 
    }

    // �迭 ũ�� Ȯ��
    int* NewArray = new int[20]; // ���ο� ũ���� �迭 ����

    // ���� �迭 ����
    for (int i = 0; i < 10; i++)
    {
        NewArray[i] = DynamicArray[i];
    }

   
    for (int i = 10; i < 20; i++)
    {
        NewArray[i] = (i - 9) * 4; 
    }

    // ���� �迭 ����
    delete[] DynamicArray;

    // DynamicArray�� ���ο� �迭�� ����Ű���� ����
    DynamicArray = NewArray;

    // ��� ���
    for (int i = 0; i < 20; i++)
    {
        cout << DynamicArray[i] << " ";
    }

    // ���� �迭 ����
    delete[] DynamicArray;

    return 0;
}
*/