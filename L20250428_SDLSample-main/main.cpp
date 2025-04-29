#include "SDL3/SDL.h" // SDL3 라이브러리 헤더 포함

#pragma comment(lib, "SDL3") // SDL3 라이브러리를 링크

int main()
{
    // SDL 초기화 (비디오 및 오디오 서브시스템 활성화)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // SDL 창 생성
    // "Sample"이라는 제목의 640x480 크기의 창을 생성하며, OpenGL을 사용
    SDL_Window* MyWindow = SDL_CreateWindow("Sample", 640, 480, SDL_WINDOW_OPENGL);

    // SDL 렌더러 생성
    // 창에 그리기 작업을 수행할 렌더러를 생성
    SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

    bool IsRunning = true; // 메인 루프 실행 여부를 제어하는 플래그
    SDL_Event MyEvent;     // SDL 이벤트 구조체

    int PlayerX = 100;
    int PlayerY = 100;

    int NumKeys = 0;

    const bool* KeyStates = SDL_GetKeyboardState(&NumKeys);

    Uint64 CurrentTime = SDL_GetTicks();
    Uint64 LastTime = SDL_GetTicks();
    Uint64 DeltaSeconds = 0;

    // 메인 루프
    while (IsRunning)
    {
        CurrentTime = SDL_GetTicks();
        DeltaSeconds = LastTime - CurrentTime;
        LastTime = CurrentTime;

        // 이벤트 처리
        SDL_PollEvent(&MyEvent); // 이벤트 큐에서 이벤트를 가져옴
        switch (MyEvent.type)
        {
        case SDL_EVENT_QUIT: // 창 닫기 이벤트 처리
            IsRunning = false; // 루프 종료
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
            break; // 다른 이벤트는 처리하지 않음
        }

        // 화면 지우기
        // 렌더러의 색상을 검은색(0, 0, 0, 0)으로 설정
        SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
        SDL_RenderClear(MyRenderer); // 렌더러의 내용을 지움

        SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 0);
        SDL_FRect Player{ (float)PlayerX, (float)PlayerY, 100, 100 };
        SDL_RenderFillRect(MyRenderer, &Player);

        // 화면 업데이트
        SDL_RenderPresent(MyRenderer);
    }

    // SDL 리소스 정리
    SDL_DestroyRenderer(MyRenderer); // 렌더러 해제
    SDL_DestroyWindow(MyWindow);     // 창 해제

    // SDL 종료
    SDL_Quit();

    return 0; // 프로그램 종료
}
