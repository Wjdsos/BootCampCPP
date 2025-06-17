#define _WINSOCK_DEPRECATED_NO_WARNINGS // 오래된 WinSock 함수 사용 경고 비활성화

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32") // ws2_32.lib 라이브러리 링크

using namespace std;

int main()
{
    // WinSock DLL 초기화 (버전 2.2)
    WSAData wsaData;
    int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (Result != 0)
    {
        cout << "Winsock init Error" << endl;
        exit(-1); // 초기화 실패 시 프로그램 종료
    }

    // IPv4, TCP 스트림 소켓 생성
    SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET)
    {
        cout << "socket Error" << endl;
        exit(-1); // 소켓 생성 실패 시 종료
    }

    // 서버 주소 정보 설정
    struct sockaddr_in ListenSockAddr;
    memset(&ListenSockAddr, 0, sizeof(ListenSockAddr)); // 구조체 0으로 초기화
    ListenSockAddr.sin_family = PF_INET; // 주소 체계: IPv4
    ListenSockAddr.sin_addr.s_addr = inet_addr("192.168.0.5"); // 서버 IP 주소
    ListenSockAddr.sin_port = htons(32000); // 포트 번호 (네트워크 바이트 오더로 변환)

    // 서버에 연결 시도
    Result = connect(ListenSocket, (struct sockaddr*)&ListenSockAddr, sizeof(ListenSockAddr));
    if (Result == SOCKET_ERROR)
    {
        cout << "connect Error " << GetLastError() << endl;
        exit(-1); // 연결 실패 시 종료
    }

    // 서버로부터 데이터 수신
    char Buffer[1024] = { 0, };
    recv(ListenSocket, Buffer, 1024, 0);
    cout << "Server Send : " << Buffer << endl;

    // 받은 데이터를 서버로 다시 전송 (에코)
    send(ListenSocket, Buffer, strlen(Buffer), 0);

    // 소켓 닫기
    closesocket(ListenSocket);

    // WinSock DLL 해제
    WSACleanup();

    return 0;
}
