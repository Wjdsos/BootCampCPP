#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

using namespace std;

int main()
{
	//dll init
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Result != 0)
	{
		cout << "Winsock init Error" << endl;
		exit(-1);
	}

	//IPv4, Stream, TCP
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ListenSocket == INVALID_SOCKET)
	{
		cout << "socket Error" << endl;
		exit(-1);
	}

	struct sockaddr_in ListenSockAddr;
	memset(&ListenSockAddr, 0, sizeof(ListenSockAddr));
	ListenSockAddr.sin_family = PF_INET;
	ListenSockAddr.sin_addr.s_addr = INADDR_ANY; //¿¬½À
	ListenSockAddr.sin_port = htons(32000);

	Result = bind(ListenSocket, (struct sockaddr*)
		&ListenSockAddr, sizeof(ListenSockAddr));

	if (Result == SOCKET_ERROR)
	{
		cout << "bind Error " << GetLastError() << endl;
		exit(-1);
	}

	Result = listen(ListenSocket, 5);
	if (Result == SOCKET_ERROR)
	{
		cout << "listen Error " << GetLastError() << endl;
		exit(-1);
	}

	struct sockaddr_in ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(ClientSockAddr));
	int ClientSockAddrLength = sizeof(ClientSockAddr);
	SOCKET ClientSocket = accept(ListenSocket, 
		(struct sockaddr*)&ClientSockAddr, &ClientSockAddrLength);

	if (ClientSocket == INVALID_SOCKET)
	{
		cout << "accept Error " << GetLastError() << endl;
		exit(-1);
	}

	const char Message[1024] = "Hello World";
	send(ClientSocket, Message, strlen(Message), 0);

	char Buffer[1024] = { 0, };
	recv(ClientSocket, Buffer, 1024, 0);

	cout << "Client Send : " << Buffer << endl;

	closesocket(ClientSocket);
	closesocket(ListenSocket);


	//dll remove
	WSACleanup();

	return 0;
}