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

int s1;

char str[MAX_L];
char buffer[MAX_L];

void client_connection()
{
	

	struct sockaddr_in server_endpoint;
	server_endpoint.sin_family=AF_INET;
	server_endpoint.sin_port=htons(1025);
	server_endpoint.sin_addr.s_addr=inet_addr("127.0.0.1");
	s1=socket(AF_INET,SOCK_STREAM,0);
	connect(s1,&server_endpoint,sizeof(server_endpoint));
	printf("connessione eseguita! :D \n");
}

void client_close()
{
	close(s1);
}

void client_send()
{
	strcpy(str, "client: ciao");
	printf("%s \n",str);
	send(s1, str, MAX_L, 0);
	printf("Messaggio inviato! \n");
}

void client_recovery()
{
	if(recv(s1,buffer[MAX_L],MAX_L,0)!=0)
	{
		printf("Risposta ricevuta \"%s\"\n",buffer);
	}
	else
	{
		printf("Messaggio non ricevuto :( \n");
	}
}

int main()
{
	client_connection();
	client_send();
	client_close();
	return 0;
}
