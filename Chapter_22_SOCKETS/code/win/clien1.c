#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

// Create a Socket for server communication
SOCKET socketCreate(void) {
    SOCKET hSocket;
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock\n");
        exit(EXIT_FAILURE);
    }

    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

// Try to connect with server
int socketConnect(SOCKET hSocket) {
    int iRetval = -1;
    int ServerPort = 12345;
    struct sockaddr_in remote = { 0 };
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    iRetval = connect(hSocket, (struct sockaddr*)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(SOCKET hSocket, char* Rqst, short lenRqst) {
    int shortRetval = -1;
    DWORD timeout = 20000; // 20 seconds timeout

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        printf("Timeout\n");
        return -1;
    }
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

// Main driver program
int main(int argc, char* argv[]) {
    SOCKET hSocket = 0;
    char sendToServer[100] = { 0 };

    // Create socket
    hSocket = socketCreate();

    if (hSocket == INVALID_SOCKET) {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    // Connect to remote server
    if (socketConnect(hSocket) < 0) {
        perror("connect failed.\n");
        return 1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    // Send data to the server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    closesocket(hSocket);
    WSACleanup();
    return 0;
}
