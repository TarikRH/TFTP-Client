#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "gettftp.h"

#define RRQ_OPCODE 2
#define SIZE 512

int getftftp(char *server, char *file, struct addrinfo *res){
    unsigned  char buf[SIZE];
    int offset = 0;
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    buf[offset++] = 0x00;      
    buf[offset++] = RRQ_OPCODE;

    strcpy((char *)&buf[offset], file);
    offset += strlen(file) + 1; 

    strcpy((char *)&buf[offset], "octet");
    offset += strlen("octet") + 1; 


    ssize_t sent_bytes = sendto(sock,buf,offset,0,res->ai_addr,res->ai_addrlen);
    if (sent_bytes==-1){

        return -1;
    }

    return sock;
}