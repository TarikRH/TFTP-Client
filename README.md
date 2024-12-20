# TFTP Client - gettftp Program

## Description
This program implements a basic TFTP client using the TFTP protocol to interact with a TFTP server. The client can download files from the server by sending a Read Request (RRQ) message. The program takes the server address and the file name as command-line arguments and then constructs a TFTP RRQ message to request the file from the specified server.

### Authors
- CHEIKH SIDIYA Abdellahi
- RHINAOUI Mohamed Tarik

## Features
1. **Command-Line Arguments**: The program accepts two arguments, the TFTP server address and the file name to be requested.
2. **Server Interaction**: The program communicates with the TFTP server using the UDP protocol on port 1069.
3. **RRQ Request**: The program constructs and sends a Read Request (RRQ) to the server to download a specified file.
4. **IP Resolution**: The program uses the `getaddrinfo` function to resolve the server's IP address.

## Installation and Usage
### Compilation and Launch
1. Compile the source code using `gcc`:
    ```bash
    gcc -o gettftp gettftp.c
    ```
2. Run the program by passing the TFTP server address and the desired file as arguments:
    ```bash
    ./gettftp <server> <file>
    ```

### Example Usage
- To download a file from a TFTP server:
    ```bash
    ./gettftp srvtpinfo1.ensea.fr file.txt
    ```

### Dependencies
- `gcc` for compilation.
- Standard C libraries: `stdio.h`, `stdlib.h`, `string.h`, `sys/types.h`, `sys/socket.h`, `netdb.h`, `arpa/inet.h`.

## Code Details
The TFTP client uses the following system calls:
- `getaddrinfo`: Resolves the server's IP address.
- `socket`: Creates a UDP socket for communication.
- `sendto`: Sends the RRQ request to the server.

### Example Code (gettftp.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "gettftp.h"

int main(int argc, char *argv[]) {

    if (argc != 3) { 
        fprintf(stderr, "Usage : %s <server> <file>
", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];   // Server address
    char *file = argv[2];      // File name

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_DGRAM;  // UDP

    int status = getaddrinfo(server, "1069", &hints, &res); // Port 1069 is used
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s
", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr)); 

    // Send the TFTP Read Request (RRQ)
    int rqq = gettftp(server, file, res);
    printf("%d
", rqq);

    printf("Server :%s 
File : %s
", server, file);
    printf("IP Address : %s
", ipstr);

    freeaddrinfo(res);
    exit(EXIT_SUCCESS);
}
```


