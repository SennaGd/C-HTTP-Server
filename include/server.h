#ifndef SERVER_H 
#define SERVER_H 
#include <bits/sockaddr.h>
#include <netinet/in.h>
#include <sys/socket.h>


struct sockaddr_in create_address(int port, sa_family_t address_family);
void create_server(int port);

#endif
