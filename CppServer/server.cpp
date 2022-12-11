#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    // Create a socket
    // AF_INET: IPv4, SOCK_STREAM: TCP, 0: default protocol
    // AF_INET6: IPv6, SOCK_DGRAM: UDP
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    bind(socketfd, (sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(socketfd, SOMAXCONN);

    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_len = sizeof(clnt_addr);
    bzero(&clnt_addr, clnt_addr_len);
    int connfd = accept(socketfd, (sockaddr*)&clnt_addr, &clnt_addr_len);
    
    printf("new client fd %d! IP: %s Port: %d\n", connfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));

    return 0;
}