#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "gettftp.h"

int main(int argc, char *argv[]){

    if (argc != 3) { // Handles the error if there are not enough arguments
        fprintf(stderr, "Usage : %s <serveur> <fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];   // Server adress
    char *file = argv[2];  // File name

    struct addrinfo hints,*res;
    memset(&hints,0,sizeof(hints));

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_DGRAM; // UDP 

    printf("Serveur :%s \nFichier : %s\n",server,file);
    printf("Adresse IP : %s\n", ipstr);
    freeaddrinfo(res);
    exit(EXIT_SUCCESS);
}   
