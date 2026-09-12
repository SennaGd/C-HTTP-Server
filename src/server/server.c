#include <bits/sockaddr.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "server.h"
#include "socket.c"

#include "routes.h"
void fetch_client_info(HTTPRequest* req, char* client_buff) 
{
		if (sscanf(client_buff, "%15s %255s %15s", req->method, req->path, req->protocol)){
			printf("path: %s\n", req->path);
		}
}

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
	for(;;) {
		int client_socket = accept(s_socket,NULL,NULL);
		char client_buff[1024];
			
		ssize_t bytes_read = read(client_socket, client_buff, sizeof(client_buff)-1);
		if ( bytes_read < 0 ) {
			printf("-- No bytes read, closing client connection!\n");
			close(client_socket);
		} 

		client_buff[bytes_read] = '\0';
		
		// -- print client requests -- //
		printf("-- Received Request --\n%s\n---------------------\n", client_buff);
		
		// -- fetching client request -- //
		HTTPRequest request;	
		fetch_client_info(&request, client_buff);	

		printf("request parsed through 'fetch_client_info': %s\n\n", request.path);
		
		printf("%s", route_info.path);
		// -- fetch correct route data | file data -- //
			
		
		// char server_message[256] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
		// char server_message2[256] = "<a href='welcome'>clickme</a>";
		//
		//	send(client_socket, server_message, strlen(server_message), 0);
		//	send(client_socket, server_message2, strlen(server_message2), 0);
		

		close(client_socket);
	}
}
