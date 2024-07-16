// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n, len;
    
    sendto(sockfd, (const char *)"Hello from UDP client", strlen("Hello from UDP client"), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
    printf("Hello message sent.\n");
    
    n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *) &servaddr, &len);
    buffer[n] = '\0';
    printf("Received from Server : \"%s\"\n", buffer);

    close(sockfd);
    return 0;
}


#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFLEN 512
#define PORT 9876

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(void)
{
    int sockfd;
    struct sockaddr_in si_other;
    int slen = sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        die("socket() failed");
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &si_other.sin_addr) <= 0) {
        die("inet_pton() failed");
    }

    while (1) {
        printf("Enter message: ");
        fgets(message, BUFLEN, stdin);
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *) &si_other, slen);
        recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);
        printf("Server Response: %s\n", buf);
    }

    close(sockfd);
    return 0;
}

#endif