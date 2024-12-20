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
    char *file = argv[2]; // File name

    struct addrinfo hints,*res;
    memset(&hints,0,sizeof(hints));

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_DGRAM; // UDP 

    int status = getaddrinfo(server, "1069", &hints, &res); // 1069 is the current PORT
 
    if (res==NULL){ // verify the value of res
        printf("Res is null");
    }
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }


    // Binary to Str
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr)); 

    // Call the gettftp function to send a TFTP (RRQ) request
    int rqq = gettftp(server,file,res);
    printf("%d\n",rqq);

    printf("Serveur :%s \nFichier : %s\n",server,file);
    printf("Adresse IP : %s\n", ipstr);
    freeaddrinfo(res);
    exit(EXIT_SUCCESS);
}   
