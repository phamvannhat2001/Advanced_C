#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 12345
#define BUFFER_SIZE 200

SOCKET socketCreate(void) {
    SOCKET hSocket;
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock");
        exit(EXIT_FAILURE);
    }

    printf("Created the socket\n");

    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(SOCKET hSocket) {
    int iRetval = -1;
    struct sockaddr_in serverAddress = { 0 };

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    iRetval = bind(hSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    return iRetval;
}

int main(int argc, char* argv[]) {
    SOCKET socket_desc = 0, sock = 0;
    struct sockaddr_in client;
    int clientLen = sizeof(client);
    char client_message[BUFFER_SIZE] = { 0 };
    char message[BUFFER_SIZE] = { 0 };

    // Create socket
    socket_desc = socketCreate();

    if (socket_desc == INVALID_SOCKET) {
        printf("Could not create socket");
        return 1;
    }

    printf("Socket created\n");

    // Bind
    if (bindCreatedSocket(socket_desc) == SOCKET_ERROR) {
        perror("bind failed");
        return 1;
    }

    printf("bind done\n");

    // Listen
    if (listen(socket_desc, 3) == SOCKET_ERROR) {
        perror("listen failed");
        return 1;
    }

    printf("Waiting for incoming connections...\n");

    // Accept connection from an incoming client
    sock = accept(socket_desc, (struct sockaddr*)&client, &clientLen);

    if (sock == INVALID_SOCKET) {
        perror("accept failed");
        return 1;
    }

    printf("Connection accepted\n");
    memset(client_message, '\0', sizeof(client_message));
    memset(message, '\0', sizeof(message));

    // Receive a reply from the client
    if (recv(sock, client_message, BUFFER_SIZE, 0) == SOCKET_ERROR) {
        printf("recv failed");
    }

    printf("Received from Client: %s\n", client_message);

    int i = atoi(client_message);
    i--;
    sprintf(message, "%d", i);

    closesocket(sock);

    printf("Waiting for incoming connections...\n");

    // Accept connection from an incoming client
    sock = accept(socket_desc, (struct sockaddr*)&client, &clientLen);

    if (sock == INVALID_SOCKET) {
        perror("accept failed");
        return 1;
    }

    printf("Connection accepted\n");

    // Send some data
    if (send(sock, message, strlen(message), 0) == SOCKET_ERROR) {
        printf("Send failed");
        return 1;
    }

    closesocket(sock);
    closesocket(socket_desc);
    WSACleanup();

    return 0;
}
