#include <iostream>

using namespace std;

int main()
{
    int N = 0; // �Է¹��� ������ ����
    cin >> N; // ������ ���� �Է�

    long long X = 0; // �Է¹��� ���ڸ� ������ ����
    long long Store = 0; // ����� ������ ����

    // N���� ���ڿ� ���� �ݺ�
    for (int i = 0; i < N; ++i)
    {
        cin >> X; // ���� �Է�

        // 1���� 62������ ������ ���� �ݺ� (2^j ���)
        for (int j = 1; j < 63; ++j)
        {
            unsigned long long NPOT = 1 << j; // 2�� j�� ���

            // NPOT(2^j)�� X���� ū ���
            if (NPOT > X)
            {
                // Store�� 0�� ���, ���� NPOT ���� ����
                if (Store == 0)
                {
                    Store = NPOT;
                }
                else
                {
                    // Store�� �̹� ���� �ִ� ���, NPOT�� XOR ���� ����
                    Store = Store ^ NPOT;
                }
                break; // �� �̻� �ݺ��� �ʿ� �����Ƿ� ����
            }
        }
    }

    // ���� ��� ���
    cout << Store << endl;

    return 0;
}
