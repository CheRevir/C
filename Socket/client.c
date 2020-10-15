#include<stdio.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<unistd.h>

#include<arpa/inet.h>

#define PORT 6666

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;
    char sendbuf[200];
    char recvbuf[200];
    int iDataNum;
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        return 1;
    }
    printf("连接到服务器");
    while(1)
    {
        printf("发送消息：");
        scanf("%s", sendbuf);
        printf("\n");
        send(client_socket, sendbuf, strlen(sendbuf), 0);
        if(strcmp(sendbuf, "quit") == 0)
            break;
        printf("读取消息：");
        recvbuf[0] = '\0';
        iDataNum = recv(client_socket, recvbuf, 200, 0);
        recvbuf[iDataNum] = '\0';
        printf("%s\n", recvbuf);
    }
    close(client_socket);
    return 0;
}
