#include "connect.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int ConnectToServer(const char *ip, int port)
{
  int sockfd;
  struct sockaddr_in servaddr;
  // Creating socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0)
  {
    perror("inet_pton failed");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
  {
    perror("connect failed");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  return sockfd;
}
int DisconnectFromServer(int sockfd)
{
  close(sockfd);
  return 0;
}
