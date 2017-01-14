#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_L 16

int client_connection()
{
	
	int s1;
	struct sockaddr_in server_endpoint;
	server_endpoint.sin_family=AF_INET;
	server_endpoint.sin_port=htons(1025);
	server_endpoint.sin_addr.s_addr=inet_addr("127.0.0.1");
	s1=socket(AF_INET,SOCK_STREAM,0);
	connect(s1,&server_endpoint,sizeof(server_endpoint));
	printf("connessione eseguita! :D \n");

	return s1;
}

void client_close(int s)
{
	close(s);
}

int client_send(int s)
{
	send(s, "ciao", 4, 0);
	printf("Messaggio inviato! \n");
	
	return s;
}

/*void client_recovery()
{
	if(recv(s,buffer[MAX_L],MAX_L,0)!=0)
	{
		printf("Risposta ricevuta \"%s\"\n",buffer);
	}
	else
	{
		printf("Messaggio non ricevuto :( \n");
	}
}*/

int main()
{
	int s = client_connection();
	s = client_send(s);
	client_close(s);

	return 0;
}
