#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Server_header.h"

using namespace std;


int main() {
	long SUCCESFULL;
	WSADATA WinSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1);
	SUCCESFULL = WSAStartup(DLLVERSION, &WinSockData);
	SOCKADDR_IN ADRESS;
	int AdressSize = sizeof(ADRESS);
	SOCKET Sock_LISTEN;
	SOCKET Sock_CONNECTION;
	Sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	ADRESS.sin_addr.S_un.S_addr = INADDR_ANY;
	ADRESS.sin_family = AF_INET;
	ADRESS.sin_port = htons(9002);
	if (Sock_CONNECTION == -1)
		cout << "Something wrong with creating a socket\n\n";

	Sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
	bind(Sock_LISTEN, (SOCKADDR*)&ADRESS, sizeof(ADRESS));
	listen(Sock_LISTEN, SOMAXCONN);
	if (Sock_LISTEN == -1)
		cout << "Something wrong with creating a socket\n\n";

	while (13) {
		cout << "SERVER: Waiting for connection\n";
		cout << ADRESS.sin_addr.s_addr;
		ADRESS.sin_addr.S_un.S_addr = INADDR_ANY;
		cout << "\n";

		if (Sock_CONNECTION = accept(Sock_LISTEN, (SOCKADDR*)&ADRESS, &AdressSize)) {
			cout << "\n" << Sock_CONNECTION << "\n\n";
			cout << "\t\tConnection was found. Enter your message\n";
			char message[256];
			while (1) {
				scanf("%s", message);
				cout << "\n";
				SUCCESFULL = send(Sock_CONNECTION, message, 256, NULL);
				if (message[0] == 'q')
					break;
			}
		}
	}



	return 0;
}