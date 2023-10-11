/*
============================================================================
Name : 34.c
Author : Dibyarup Pal
Description : Write a program to create a concurrent server.
		a. use fork
		b. use pthread_create 
Date: 11th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

#define PORT 9022
#define MAX_CLIENTS 10

void *client_handler(void *arg);

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(){
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t threads[MAX_CLIENTS];

    //Create a socket
    //"server_socket" is socket descriptor of server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
        error("Error in Socket creation");
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    //specified Destination address of the socket 
    //INADDR_ANY automatically assigns IP address of the current machine
    server_addr.sin_addr.s_addr = INADDR_ANY;
    

    //Bind the socket to the specified IP Address and port
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error("Error in Binding");

    //Listen for incoming connections
    if(listen(server_socket, MAX_CLIENTS) == -1)
        error("Error in Listening");

    printf("Server is Listening to Port %d\n", PORT);

    while(1){
        //Accept a new Connection
        //Server will wait at this line till a client connects with proper IP address and Port number
        //"client_socket" is socket descriptor for client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if(client_socket == -1){
            perror("Error in accepting client");
            continue;
        }

        //Create a new thread to handle the client
        pthread_create(&threads[MAX_CLIENTS], NULL, client_handler, (void *)&client_socket);
    }

    //closing the server after closing the connection
    close(server_socket);
    
    return 0;
}

void *client_handler(void *arg){
    int client_socket = *((int *)arg);
    char buffer[1024];
    int bytes_received;

    while(1){
        
        int bytes_received = read(client_socket, buffer, sizeof(buffer));
        if(bytes_received == -1){
            perror("Error in receiving data");
            close(client_socket);
            pthread_exit(NULL);
        }

        if(bytes_received == 0){
            printf("Client Disconnected\n");
            close(client_socket);
            pthread_exit(NULL);
        }
        buffer[bytes_received] = '\0';

        write(1,"Received : ",11);
        write(1,buffer,strlen(buffer));
        write(1,"\n",1);

        write(client_socket, buffer, bytes_received);
        memset(buffer, '\0', sizeof(buffer));
    }
}
