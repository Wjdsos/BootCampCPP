#include <iostream>

using namespace std;

// DynamicArray[10]을 DynamicArray[20]으로 늘리고 [10]~[19]까지 4의 배수 넣기

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
    int* DynamicArray = new int[10]; // 동적 배열 생성

    for (int i = 0; i < 10; i++)
    {
        DynamicArray[i] = (i + 1) * 3; 
    }

    // 배열 크기 확장
    int* NewArray = new int[20]; // 새로운 크기의 배열 생성

    // 기존 배열 복사
    for (int i = 0; i < 10; i++)
    {
        NewArray[i] = DynamicArray[i];
    }

   
    for (int i = 10; i < 20; i++)
    {
        NewArray[i] = (i - 9) * 4; 
    }

    // 기존 배열 해제
    delete[] DynamicArray;

    // DynamicArray가 새로운 배열을 가리키도록 설정
    DynamicArray = NewArray;

    // 결과 출력
    for (int i = 0; i < 20; i++)
    {
        cout << DynamicArray[i] << " ";
    }

    // 최종 배열 해제
    delete[] DynamicArray;

    return 0;
}
*/