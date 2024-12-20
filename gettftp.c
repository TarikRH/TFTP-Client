#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "gettftp.h"
#include <unistd.h>

#define RRQ_OPCODE 1
#define SIZE 512

int gettftp(char *server, char *file, struct addrinfo *res) {
    unsigned char buf[SIZE]; 
    int offset = 0;          // Offset to write data in the buffer

    // Creating a socket
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // Add the TFTP opcode for RRQ to the buffer
    buf[offset++] = 0x00;      
    buf[offset++] = RRQ_OPCODE;


    // Add the requested file name to the buffers
    offset += strlen(file) + 1;

    // Add the transfer mode "octet" to the buffer
    strcpy((char *)&buf[offset], "octet");
    offset += strlen("octet") + 1;

    
    ssize_t sent_bytes = sendto(sock, buf, offset, 0, res->ai_addr, res->ai_addrlen); // Send the TFTP request to the server

    if (sent_bytes == -1) { // If there is an error while sending the request, then return -1
        
        return -1;
    }
    return sock;
}