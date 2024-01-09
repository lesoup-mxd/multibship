#ifndef CONNECT_H
#define CONNECT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ConnectToServer(const char *ip, int port);
int DisconnectFromServer(int sockfd);

#endif // CONNECT_H
