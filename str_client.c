#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define MAX 800
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd)
{
    char buff[MAX];
    int cnt = 0;
    int n,c;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("\nEnter the string to be processed in the given format \n");
        printf("1#<str> for converting <str> to UPPER CASE \n");
        printf("2#<str> for converting <str> to LOWER CASE \n");
        printf("3#<str> to check if <str> is a PALINDROME \n");
        printf("4#<str> for REVERSING the <str> \n");
        printf("5#<str> for finding the LENGTH of the <str> \n");
        printf("6#<str> for checking if <str> is a PANAGRAM\n");
        printf("7#<str>#<str> for checking if  the <str> and <str> are ANAGRAMS  \n");
        printf("8#<str> for checking if <str> is a ISOGRAM\n");
        printf("exit for EXITING the application \n");
        printf("\n Enter the string : ");

        n = 0;
        while ((buff[n++] = getchar()) != '\n');

        printf("sending : %s \n",buff);
        write(sockfd, buff, sizeof(buff));

        if ((strncmp(buff, "exit", 4)) == 0) 
        {
            printf("Client Exit...\n");
            break;
        }

        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server  : %s \n", buff);
                
    }
}
   
int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
   
    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
   
    // function for chat
    func(sockfd);
   
    // close the socket
    close(sockfd);
}