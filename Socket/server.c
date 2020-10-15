#include<stdio.h>
#include<string.h>

//socket
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#include<arpa/inet.h>

#define PORT 6666

int main()
{
    int server_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addr_len = sizeof(client_addr);
    int client;
    char buffer[200];
    int iDataNum;

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return 1;
    }


    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        return 1;
    }

    if(listen(server_socket, 5) < 0)
    {
        perror("listen");
        return 1;
    }

    while(1)
    {
        printf("端口：%d\n", PORT);
        client = accept(server_socket, (struct sockaddr *) &client_addr, (socklen_t *) &addr_len);
        if(client < 0)
        {
            perror("accept");
            continue;
        }
        printf("等待消息...\n");
        printf("IP: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Port: %d\n", htons(client_addr.sin_port));

        while(1)
        {
            printf("读取消息：");
            buffer[0] = '\0';
            iDataNum = recv(client, buffer, 1024, 0);
            if(iDataNum < 0)
            {
                perror("recv null");
                continue;
            }
            buffer[iDataNum] = '\0';
            if(strcmp(buffer, "quit") == 0)
                break;
            printf("%s\n", buffer);
            printf("发送消息：");
            scanf("%s", buffer);
            printf("\n");
            send(client, buffer, strlen(buffer), 0);
            if(strcmp(buffer, "quit") == 0)
                break;
        }
    }
    close(server_socket);
    return 0;
}
