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

	// 서버 소켓 주소 구조체 설정
	struct sockaddr_in ListenSockAddr;
	memset(&ListenSockAddr, 0, sizeof(ListenSockAddr));
	ListenSockAddr.sin_family = PF_INET; // 주소 체계: IPv4
	ListenSockAddr.sin_addr.s_addr = INADDR_ANY; // 모든 IP에서 연결 허용
	ListenSockAddr.sin_port = htons(32000); // 포트 번호 32000

	// 소켓에 주소 바인딩
	Result = bind(ListenSocket, (struct sockaddr*)
		&ListenSockAddr, sizeof(ListenSockAddr));

	if (Result == SOCKET_ERROR)
	{
		cout << "bind Error " << GetLastError() << endl;
		exit(-1);
	}

	// 연결 요청 대기 상태로 전환
	Result = listen(ListenSocket, 5);
	if (Result == SOCKET_ERROR)
	{
		cout << "listen Error " << GetLastError() << endl;
		exit(-1);
	}

	// 클라이언트 소켓 주소 구조체 및 길이 초기화
	struct sockaddr_in ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(ClientSockAddr));
	int ClientSockAddrLength = sizeof(ClientSockAddr);

	// 클라이언트의 연결 요청 수락
	SOCKET ClientSocket = accept(ListenSocket,
		(struct sockaddr*)&ClientSockAddr, &ClientSockAddrLength);

	if (ClientSocket == INVALID_SOCKET)
	{
		cout << "accept Error " << GetLastError() << endl;
		exit(-1);
	}

	// 클라이언트에게 메시지 전송
	const char Message[1024] = "Hello World";
	send(ClientSocket, Message, strlen(Message), 0);

	// 클라이언트로부터 데이터 수신
	char Buffer[1024] = { 0, };
	recv(ClientSocket, Buffer, 1024, 0);

	cout << "Client Send : " << Buffer << endl;

	// 소켓 닫기
	closesocket(ClientSocket);
	closesocket(ListenSocket);

	// Winsock DLL 정리
	WSACleanup();

	return 0;
}
