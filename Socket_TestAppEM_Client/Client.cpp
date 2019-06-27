#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Client_header.h"

using namespace std;


int main() {
	long SUCCESFULL;
	WSADATA WinSockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 1);
	SUCCESFULL = WSAStartup(DLLVERSION, &WinSockData);
	SOCKADDR_IN ADRESS;


	char RESPONSE;
	string CONVERTER;
	char message[256];

	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);
	ADRESS.sin_addr.s_addr = ADDR_ANY;// inet_addr("127.0.0.1");  //inet_addr("194.44.36.30");
	ADRESS.sin_family = AF_INET;
	ADRESS.sin_port = htons(9002);
	while (13) {
		cout << "Would you like to connect? Y if yes, N if no\n";
		RESPONSE = _getch();
		if (RESPONSE == 'Y' || RESPONSE == 'y') {
			connect(sock, (SOCKADDR*)&ADRESS, sizeof(ADRESS));
			SUCCESFULL = recv(sock, message, 256, NULL);
			CONVERTER = message;
			cout << "Server sent an information: " << CONVERTER << "\n";
		}
		if (RESPONSE == 'N' || RESPONSE == 'n')
			break;
	}

	return 0;
}
