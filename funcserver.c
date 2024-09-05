// webserver.c
#include "server.h"

void create_socket(int *sockfd) {
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd == -1) {
        perror("webserver (socket)");
        _exit(1);
    }
    printf("socket created successfully\n");
}

void bind_socket(int sockfd, struct sockaddr_in *host_addr) {
    int host_addrlen = sizeof(*host_addr);
    host_addr->sin_family = AF_INET;
    host_addr->sin_port = htons(PORT);
    host_addr->sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)host_addr, host_addrlen) != 0) {
        perror("webserver (bind)");
        _exit(1);
    }
    printf("socket successfully bound to address\n");
}

void listen_socket(int sockfd) {
    if (listen(sockfd, SOMAXCONN) != 0) {
        perror("webserver (listen)");
        _exit(1);
    }
    printf("server listening for connections\n");
}

void accept_connections(int sockfd) {
    char buffer[BUFFER_SIZE];
    char resp[] = "HTTP/1.0 200 OK\r\n"
                  "Server: webserver-c\r\n"
                  "Content-type: text/html\r\n\r\n"
                  "<html>hello, world</html>\r\n";
    struct sockaddr_in host_addr, client_addr;
    int host_addrlen = sizeof(host_addr);
    int client_addrlen = sizeof(client_addr);

    for (;;) {
        int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr, (socklen_t *)&host_addrlen);
        if (newsockfd < 0) {
            perror("webserver (accept)");
            continue;
        }
        printf("connection accepted\n");

        int sockn = getsockname(newsockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addrlen);
        if (sockn < 0) {
            perror("webserver (getsockname)");
            continue;
        }

        int valread = read(newsockfd, buffer, BUFFER_SIZE);
        if (valread < 0) {
            perror("webserver (read)");
            continue;
        }

        char method[BUFFER_SIZE], uri[BUFFER_SIZE], version[BUFFER_SIZE];
        sscanf(buffer, "%s %s %s", method, uri, version);
        printf("[%s:%u] %s %s %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), method, version, uri);

        int valwrite = write(newsockfd, resp, strlen(resp));
        if (valwrite < 0) {
            perror("webserver (write)");
            continue;
        }

        close(newsockfd);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in host_addr;

    create_socket(&sockfd);
    bind_socket(sockfd, &host_addr);
    listen_socket(sockfd);
    accept_connections(sockfd);

    return 0;
}

