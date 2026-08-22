#include "server.h"
#include "socket.c"
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>

void create_server(int port)
{
	int s_socket = create_socket(); // Server Socket

	// defining server address 
	// etc, url.
	struct sockaddr_in server_address; 
	server_address.sin_port = htons(9002);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;

	int server_bind = bind(s_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	printf("server bind returned: %d", server_bind);
	listen(s_socket, 5);

	while ( true ) {
		int client_socket = accept(s_socket,NULL,NULL);

		char server_message[256] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
		send(client_socket, server_message, sizeof(server_message), 0);
		close(client_socket);
	}
	// if (server_bind < 0){
	// 	printf("Could not bind server to address.\n");
	// 	exit(EXIT_FAILURE);
	// }

}
