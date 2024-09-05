// webserver.h
#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void create_socket(int *sockfd);
void bind_socket(int sockfd, struct sockaddr_in *host_addr);
void listen_socket(int sockfd);
void accept_connections(int sockfd);

#endif

