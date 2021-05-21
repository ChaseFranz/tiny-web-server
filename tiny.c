/*
* tiny.c
*
*/

#include "csapp.h"

void doit(int fd);
void read_requesthdrs(rio_t *rp);
int parse_uri(char *uri, char *filename. char *cgiargs);
int serve_static(int fd, char *filename, int filesize);
void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char *filenamem char *cgiargs);
void clienterror(int fd, char *cause, char *errnumm, char *shortmsg, char *longmsg)

int main(int argcm char **argv)
{
    int listenfd;
    int connfd;
    char hostname[MAXLINE], 
    char port[MAXLINE];
    socklen_t clientLength;
    struct sockaddr_storage clientAddress;
    char alwaysTrue = 1;

    // Check command-line args
    if (argc != 2)
    {
        fprintf(stderr, "usage %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = Open_listenfd(argv[1]);
    
    while(alwaysTrue)
    {
        clientLength = sizeof(clientAddress);
        connfd = Accept(listenfd, (SA *)&clientAddress, &clientLength);
        Getnameinfo((SA *) &clientAddress, clientLength, hostname, MAXLINE port, MAXLINE, 0);
        printf("Accepted connection from (%s, %s\n)", hostname, port);
        Close();
    }
}