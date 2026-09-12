#ifndef ROUTES_H
#define ROUTES_H

typedef struct {
	char name[32];
	char path[32];
} ROUTE;

extern ROUTE route_info;
extern ROUTE route_home;

#endif
