#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
    // Describe what kind of address/socket we want
    struct addrinfo hints = {0};
    struct addrinfo *res;

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP

    // DNS lookup: "google.com" -> IP + port 80
    if (getaddrinfo("google.com", "80", &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    // Create a socket FD (just like open(), but for network)
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // Establish TCP connection (3-way handshake)
    connect(sock, res->ai_addr, res->ai_addrlen);

    // HTTP request bytes written to the socket
    const char *req =
        "GET / HTTP/1.1\r\n"
        "Host: google.com\r\n"
        "Connection: close\r\n"
        "\r\n";

    // write() sends bytes into the TCP socket buffer
    write(sock, req, strlen(req));

    // Read response bytes from the socket
    char buf[1024];
    ssize_t n = read(sock, buf, sizeof(buf) - 1);
    buf[n] = 0; // make it a C string

    // Check HTTP status line
    if (strstr(buf, "200 OK"))
        printf("HTTP 200 OK\n");
    else
        printf("Not 200\n");

    printf("%s\n", buf);
    // Close socket FD (releases kernel socket state)
    close(sock);

    // Free DNS result memory
    freeaddrinfo(res);

    return 0;
}
