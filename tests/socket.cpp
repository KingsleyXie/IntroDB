#include <bits/stdc++.h>
#include <winsock2.h>
#include <io.h>

#define PORT 2333
#define DEFAULT_BUFLEN 4096

// This only works in Visual Studio
// Add "-lwsock32" option if compile with gcc
#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
	WSADATA wsa;
	SOCKET s, connection;
	struct sockaddr_in server, client;
	int c;
	std::string sendback;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
		throw "Socket Starting Failed";

	if ((s = socket(AF_INET, SOCK_STREAM, 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
	}

	listen(s, 3);
	c = sizeof(struct sockaddr_in);
	connection = accept(s, (struct sockaddr *)&client, &c);
	if (connection == INVALID_SOCKET)
	{
		printf("accept failed with error code : %d", WSAGetLastError());
	}

	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	int result;

	do
	{
		result = recv(connection, recvbuf, recvbuflen, 0);
		if (result > 0)
		{
			printf("Bytes received: %d\n", result);
			sendback = "Recieved your data\n";
			send(connection, sendback.c_str(), sendback.length(), 0);
		}
		else if (result == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());

	} while(result > 0);

	closesocket(s);
	WSACleanup();
	return 0;
}
