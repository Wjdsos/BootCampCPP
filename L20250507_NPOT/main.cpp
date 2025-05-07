#include <iostream>

using namespace std;

int main()
{
    int N = 0; // 입력받을 숫자의 개수
    cin >> N; // 숫자의 개수 입력

    long long X = 0; // 입력받을 숫자를 저장할 변수
    long long Store = 0; // 결과를 저장할 변수

    // N개의 숫자에 대해 반복
    for (int i = 0; i < N; ++i)
    {
        cin >> X; // 숫자 입력

        // 1부터 62까지의 지수에 대해 반복 (2^j 계산)
        for (int j = 1; j < 63; ++j)
        {
            unsigned long long NPOT = 1 << j; // 2의 j승 계산

            // NPOT(2^j)이 X보다 큰 경우
            if (NPOT > X)
            {
                // Store가 0인 경우, 현재 NPOT 값을 저장
                if (Store == 0)
                {
                    Store = NPOT;
                }
                else
                {
                    // Store가 이미 값이 있는 경우, NPOT과 XOR 연산 수행
                    Store = Store ^ NPOT;
                }
                break; // 더 이상 반복할 필요 없으므로 종료
            }
        }
    }

    // 최종 결과 출력
    cout << Store << endl;

    return 0;
}
