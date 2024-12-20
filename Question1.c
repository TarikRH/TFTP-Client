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

    char *server = argv[1];  // Server adress
    char *file = argv[2]; // File name

}
