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

int s1,s2;
char buffer[MAX_L];
//char str[MAX_L];

void server_connection()
{
	struct sockaddr_in server_endpoint, client_endpoint;

	server_endpoint.sin_family = AF_INET;
	server_endpoint.sin_port = htons(1025);
	server_endpoint.sin_addr.s_addr = INADDR_ANY;

	s1 = socket(AF_INET,SOCK_STREAM,0);

	bind(s1,&server_endpoint,sizeof(server_endpoint));

	listen(s1,10);
	
	s2 = accept(s1,&client_endpoint,sizeof(client_endpoint));
	
	printf("connessione eseguita! :D \n");
}

void server_close()
{
	close(s1);
	close(s2);
}

/*int server_send(int s)
{
	strcpy(str, "server: ciao");
	send(s2, str, 15, 0);
}*/

void server_recovery()
{
	printf("dentro la function \n");
	char str[4];
	int N = recv(s2,&str,4,0);
	printf("%d",N);
	while(N>0)
	{
		printf("dentro il while \n");
		printf("stringa: %s \n",str);
		N = recv(s2,&str,4,0);
	}

}

int main()
{
	server_connection();
	server_recovery();
	server_close();
	
	return 0;
}
