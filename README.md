# TP Synthesis – TFTP Client

## Description
The project consists of creating a TFTP client in C to exchange files using the TFTP protocol. The program must be capable of downloading and uploading files to a TFTP server. It interacts with the server through RRQ (Read Request) and WRQ (Write Request) messages using the UDP protocol.

The project includes using RFCs related to TFTP (RFC1350, RFC2347, RFC2348, RFC2349, RFC7440) as well as Wireshark captures to validate the proper functioning of the application.

### Authors
- CHEIKH SIDIYA Abdellahi
- RHINAOUI Mohamed Tarik

## Features
1. **Server Interaction**: The client allows connecting to a TFTP server, downloading (GET), and uploading (PUT) files.
2. **Command-Line Arguments**: The program accepts command-line arguments to specify the server and the file to transfer.
3. **RRQ (Read Request)**: The program constructs and sends an RRQ to the server to download a file.
4. **WRQ (Write Request)**: The program can also send a WRQ to upload a file to the server.

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
- To upload a file to a TFTP server:
    ```bash
    ./puttftp srvtpinfo1.ensea.fr file.txt
    ```

### Dependencies
- `gcc` for compilation.
- Standard C libraries: `stdio.h`, `stdlib.h`, `string.h`, `sys/types.h`, `sys/socket.h`, `netdb.h`, `arpa/inet.h`.

## Code Details
The TFTP client uses the following system calls:
- `getaddrinfo`: Resolves the server's IP address.
- `socket`: Creates a UDP socket for communication.
- `sendto`: Sends requests and data to the server.
- `recvfrom`: Receives responses from the server.

