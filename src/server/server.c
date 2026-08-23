#include <bits/sockaddr.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>

#include "server.h"
#include "socket.c"

struct sockaddr_in create_address(int port, sa_family_t address_family)
{
	if (port < 0) {
		printf("Invalid Port, Shutting down");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in server_address;	
	server_address.sin_port = htons(port);
	server_address.sin_family = address_family;
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	return server_address;
}


void create_server(int port)
{

	int s_socket = create_socket(); // Server Socket

	struct sockaddr_in server_address = create_address(
			port,
			AF_INET
	);

	int server_bind = bind(
			s_socket,
			(struct sockaddr*) &server_address,
			sizeof(server_address)
	);
	
	if (server_bind < 0) {
		printf("Failed to bind server to port: %d\n", port); 
		exit(EXIT_FAILURE);
	} else { // start server listener
		printf("Server listening on port: '\e]8;;http://127.0.0.1:%d\e\\127.0.0.1:%d\e]8;;\e\\'  \n", port, port);
		listen(s_socket, 5); // Listen for requests
	}		


	// keep server active || server loop
	while ( true ) {
		int client_socket = accept(s_socket,NULL,NULL);

		char server_message[256] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
		send(client_socket, server_message, sizeof(server_message), 0);
		close(client_socket);
	}
}
