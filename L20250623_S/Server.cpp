#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32")

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerSockAddr.sin_port = htons(30303);

	connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, 
		sizeof(ServerSockAddr));

	FILE* OutputFile = fopen("good_copy.png", "wb");

	char Buffer[1024] = { 0, };
	size_t RecvSize = 0;
	size_t WritFileSize = 0;
	do
	{
		//send
		RecvSize = recv(ServerSocket, Buffer, sizeof(Buffer), 0);
		WritFileSize = fwrite(Buffer, sizeof(char), RecvSize, 
			OutputFile);
	} while (RecvSize > 0);

	fclose(OutputFile);
	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}