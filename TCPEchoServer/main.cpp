#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

using namespace std;

int main()
{
	// Winsock DLL 초기화
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Result != 0)
	{
		cout << "Winsock init Error" << endl;
		exit(-1);
	}

	// TCP 소켓 생성 (IPv4, 스트림, TCP)
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ListenSocket == INVALID_SOCKET)
	{
		cout << "socket Error" << endl;
		exit(-1);
	}

	// 서버 주소 정보를 위한 sockaddr_in 구조체 설정
	struct sockaddr_in ListenSockAddr;
	memset(&ListenSockAddr, 0, sizeof(ListenSockAddr));
	ListenSockAddr.sin_family = PF_INET; // 주소 체계: IPv4
	ListenSockAddr.sin_addr.s_addr = inet_addr("192.168.0.5"); // 서버 IP 주소
	ListenSockAddr.sin_port = htons(32000); // 서버 포트 (32000)

	// 서버에 연결 시도
	Result = connect(ListenSocket, (struct sockaddr*)&ListenSockAddr, sizeof(ListenSockAddr));

	if (Result == SOCKET_ERROR)
	{
		cout << "connect Error " << GetLastError() << endl;
		exit(-1);
	}

	// 서버로부터 데이터 수신
	char Buffer[1024] = { 0, };
	recv(ListenSocket, Buffer, 1024, 0);
	cout << "Server Send : " << Buffer << endl;

	// 받은 데이터를 서버로 다시 전송 (에코)
	send(ListenSocket, Buffer, strlen(Buffer), 0);

	// 소켓 닫기
	closesocket(ListenSocket);

	// Winsock DLL 정리
	WSACleanup();

	return 0;
}