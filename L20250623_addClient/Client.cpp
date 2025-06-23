#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32")

int main()
{
	srand(time(nullptr));
	char Message[1024] = { 0, };

	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);


	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerSockAddr.sin_port = htons(30303);

	connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));

	while (true)
	{
		int FirstNumber = rand() % 90 + 10;
		int SecondeNumber = rand() % 90 + 10;

		//[9][9][+][9][9][0]
		sprintf(Message, "%d+%d", FirstNumber, SecondeNumber);

		printf("%s = ", Message);

		char Buffer[1024] = { 0, };

		int SentBytes = send(ServerSocket, Message, strlen(Message), 0);

		int RecvSize = recv(ServerSocket, Buffer, 3, 0);

		if (SentBytes <= 0 || RecvSize <= 0)
		{
			printf("connection closed\n");
			break;
		}

		printf("%s\n", Buffer);
	}

	closesocket(ServerSocket);


	WSACleanup();

	return 0;
}