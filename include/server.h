#ifndef SERVER_H 
#define SERVER_H 

#include <bits/sockaddr.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef struct {
	char method[16];
	char path[256];
	char protocol[16];
} HTTPRequest;

void fetch_client_info(HTTPRequest *req, char* client_buff);

struct sockaddr_in create_address(int port, sa_family_t address_family);
void create_server(int port);

#endif
