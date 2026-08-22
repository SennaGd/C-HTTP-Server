#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>


int create_socket(){
	// define ipv4 tcp socket
	int server_socket;	
	server_socket = socket(AF_INET, SOCK_STREAM, 0); 

	if (server_socket < 0) {
		printf("Creating the socket failed (%d)\n\n", server_socket);
		exit(EXIT_FAILURE);
	}

	return server_socket;	
};
