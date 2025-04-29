#include "SDL3/SDL.h" // SDL3 ���̺귯�� ��� ����

#pragma comment(lib, "SDL3") // SDL3 ���̺귯���� ��ũ

int main()
{
    // SDL �ʱ�ȭ (���� �� ����� ����ý��� Ȱ��ȭ)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // SDL â ����
    // "Sample"�̶�� ������ 640x480 ũ���� â�� �����ϸ�, OpenGL�� ���
    SDL_Window* MyWindow = SDL_CreateWindow("Sample", 640, 480, SDL_WINDOW_OPENGL);

    // SDL ������ ����
    // â�� �׸��� �۾��� ������ �������� ����
    SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

    bool IsRunning = true; // ���� ���� ���� ���θ� �����ϴ� �÷���
    SDL_Event MyEvent;     // SDL �̺�Ʈ ����ü

    int PlayerX = 100;
    int PlayerY = 100;

    int NumKeys = 0;

    const bool* KeyStates = SDL_GetKeyboardState(&NumKeys);

    Uint64 CurrentTime = SDL_GetTicks();
    Uint64 LastTime = SDL_GetTicks();
    Uint64 DeltaSeconds = 0;

    // ���� ����
    while (IsRunning)
    {
        CurrentTime = SDL_GetTicks();
        DeltaSeconds = LastTime - CurrentTime;
        LastTime = CurrentTime;

        // �̺�Ʈ ó��
        SDL_PollEvent(&MyEvent); // �̺�Ʈ ť���� �̺�Ʈ�� ������
        switch (MyEvent.type)
        {
        case SDL_EVENT_QUIT: // â �ݱ� �̺�Ʈ ó��
            IsRunning = false; // ���� ����
            break;
        case SDL_EVENT_KEY_DOWN:
            if (KeyStates[SDL_SCANCODE_UP])
            {
                PlayerY-=10;
            }
            if (KeyStates[SDL_SCANCODE_DOWN])
            {
                PlayerY+=10;
            }
            if (KeyStates[SDL_SCANCODE_LEFT])
            {
                PlayerX-=10;
            }
            if (KeyStates[SDL_SCANCODE_RIGHT])
            {
                PlayerX+=10;
            }
            if (KeyStates[SDL_SCANCODE_ESCAPE])
            {
                IsRunning = false;
            }
            break;
        default:
            break; // �ٸ� �̺�Ʈ�� ó������ ����
        }

        // ȭ�� �����
        // �������� ������ ������(0, 0, 0, 0)���� ����
        SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
        SDL_RenderClear(MyRenderer); // �������� ������ ����

        SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 0);
        SDL_FRect Player{ (float)PlayerX, (float)PlayerY, 100, 100 };
        SDL_RenderFillRect(MyRenderer, &Player);

        // ȭ�� ������Ʈ
        SDL_RenderPresent(MyRenderer);
    }

    // SDL ���ҽ� ����
    SDL_DestroyRenderer(MyRenderer); // ������ ����
    SDL_DestroyWindow(MyWindow);     // â ����

    // SDL ����
    SDL_Quit();

    return 0; // ���α׷� ����
}
