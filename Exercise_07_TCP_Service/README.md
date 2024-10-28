# Exercise 7: Implementation of Connection-Oriented Concurrent Service (TCP)

## Description

TCP guarantees:

- Reliable, ordered, and error-checked delivery of data between applications.
- A three-way handshake to establish a connection before data transmission.
- Flow control, congestion control, and error recovery by retransmitting erroneous packets.

### Source Code

#### Server Code

The server code initializes a socket, binds it to an IP and port, listens for incoming connections, and echoes received messages back to the client.

```c
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERV_TCP_PORT 5035

int main(int argc, char **argv) {
    int sockfd, newsockfd, clength;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[4096];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    printf("\nStart");
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("\nListening...\n");
    listen(sockfd, 5);

    clength = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clength);
    printf("\nAccepted\n");

    read(newsockfd, buffer, 4096);
    printf("\nClient message: %s", buffer);

    write(newsockfd, buffer, 4096);
    printf("\n");

    close(sockfd);
    return 0;
}
```

#### Client Code

The client code establishes a TCP connection to the server, sends a message, and receives an echoed message.

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERV_TCP_PORT 5035

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[4096];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    printf("\nReady for sending...");
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("\nEnter the message to send\n");
    printf("\nClient: ");
    fgets(buffer, 4096, stdin);

    write(sockfd, buffer, 4096);
    printf("Server echo: %s", buffer);
    printf("\n");

    close(sockfd);
    return 0;
}
```

### Explanation

1. **Server**:
   - Creates a socket and binds it to a port.
   - Listens for client connections and accepts a client.
   - Reads a message from the client and sends it back (echoes it).
   - Closes the connection.

2. **Client**:
   - Creates a socket and connects to the server.
   - Sends a message to the server.
   - Reads the echoed message from the server.
   - Closes the connection.

### Output Example

#### Server

```bash
Start
Listening...

Accepted

Client message: Hello Server
```

#### Client

```bash
Ready for sending...
Enter the message to send

Client: Hello Server
Server echo: Hello Server
```
