#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>




int main(int argc, char *argv[]){

    if (argc != 3) { // Handles the error if there are not enough arguments
        fprintf(stderr, "Usage : %s <serveur> <fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *file = argv[2];

    struct addrinfo hints,*res;
    memset(&hints,0,sizeof(hints));

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP 
    
    int status = getaddrinfo(server, NULL, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr));  // Binary to Str

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    
    printf("Serveur :%s \nFichier : %s\n",server,file);
    printf("Adresse IP : %s\n", ipstr);
    freeaddrinfo(res);
    exit(EXIT_SUCCESS);
}   