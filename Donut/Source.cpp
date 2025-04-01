#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <chrono>
#include <thread>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

int main() {
    float A = 0, B = 0;
    const int width = 80;
    const int height = 22;
    const int size = width * height;

    while (true) {
        vector<char> b(size, ' ');
        vector<float> z(size, 0);

        for (float j = 0; j < 6.28; j += 0.07) {
            for (float i = 0; i < 6.28; i += 0.02) {
                float sini = sin(i), cosi = cos(i);
                float sinj = sin(j), cosj = cos(j);
                float sinA = sin(A), cosA = cos(A);
                float sinB = sin(B), cosB = cos(B);
                float cosj2 = cosj + 2;
                float mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5);
                float t = sini * cosj2 * cosA - sinj * sinA;

                int x = width / 2 + (width / 4) * mess * (cosi * cosj2 * cosB - t * sinB);
                int y = height / 2 + (height / 4) * mess * (cosi * cosj2 * sinB + t * cosB);
                int o = x + width * y;
                int N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);

                if (y < height && y >= 0 && x >= 0 && x < width && mess > z[o]) {
                    z[o] = mess;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        system(CLEAR_SCREEN);
        for (int k = 0; k < size; k++) {
            cout << (k % width ? b[k] : '\n');
        }

        A += 0.08;
        B += 0.02;
        this_thread::sleep_for(chrono::milliseconds(30));
    }

    return 0;
}
