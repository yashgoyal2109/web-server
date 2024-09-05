#include "server.h"

int main() {
    int sockfd;
    struct sockaddr_in host_addr;

    create_socket(&sockfd);
    bind_socket(sockfd, &host_addr);
    listen_socket(sockfd);
    accept_connections(sockfd);

    return 0;
}
