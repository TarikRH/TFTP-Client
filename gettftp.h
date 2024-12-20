#ifndef GETTFTP_H
#define GETTFTP_H

#define RRQ_OPCODE 2  
#define SIZE 512

#include <sys/socket.h>
#include <netdb.h>

int getftftp(char *server, char *file, struct addrinfo *res);

#endif