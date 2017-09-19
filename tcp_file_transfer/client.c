
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include <arpa/inet.h>

int main(int argc,char **argv)
{
    int sockfd,n;
    //char sendline[100];
    //char recvline[100];
    struct sockaddr_in servaddr;
    FILE *fptr;
    char line[100];
    char st[100];
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);

    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));

    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

    bzero( sendline, 100);
    bzero( recvline, 100);
    //fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
    fptr = fopen("a.txt", "r");
    while (fgets(line, 100, fptr) != NULL)
    {
    //printf(line);
    strcat(st,line);
    }
    //fscanf(fptr,"%s",e);
    write(sockfd,st,strlen(st)+1);
    //printf(e);
}
