#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
 
using namespace std;

class Client
{
private:
	int sock;
	struct sockaddr_in server;
 
	char client_message[100];
	char server_message[5000];
 

 	
public:
	Client(int port)
	{
		server.sin_family = PF_INET;
		server.sin_addr.s_addr = inet_addr("127.0.0.1");
		server.sin_port = htons(port);
	}
 
	void CreateSocket()
	{
		sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sock == -1)
		{
			cerr << "Unable to create socket\n";
			exit(-1);
		}
		cout << "Socket was created\n";
	}
 
	void Connect()
	{
		if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
		{
		cerr << "Unable to connect\n";
		exit(-2);
		}
		cout << "Connected was successfully\n";
	}
 
	void Run()
	{
		CreateSocket();
		Connect();
 
		while (true)
		{
			cout << "Enter command: ";
			cin >> client_message;
 
			if (send(sock, client_message, 100, 0) < 0)
			{
				cout << "Sending failed\n";
				exit(-3);
			}
 
			if (recv(sock, server_message, 5000, 0) < 0)
			{
				cout << "Receiving failed\n";
				break;
			}
			
			cout << server_message << '\n';
		}
		close(sock);
	}
};

int main()
{
	Client client(6660);
	client.Run();
 
	return 0;
}
