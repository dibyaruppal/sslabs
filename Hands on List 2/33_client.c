/*
============================================================================
Name : 33.c
Author : Dibyarup Pal
Description : Write a program to communicate between two machines using socket. 
Date: 10th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 9022

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(){
    	int client_socket;
    	struct sockaddr_in server_addr;

    	// create a socket
    	//"client_socket" is socket descriptor of server
    	client_socket = socket(AF_INET, SOCK_STREAM, 0);
    	if(client_socket == -1)
        	error("Error in socket creation");

    	server_addr.sin_family = AF_INET;
    	server_addr.sin_port = htons(PORT); // Port is same as specified in server
    	// specified destination address of socket
    	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);


    	// Connect to the server
    	if(connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        	error("Error in connecting to the server");

    	char message[1024];
   
        
        char display_string[] = "Enter a message to send to the server : ";
        write(1,display_string, sizeof(display_string));
        read(0,message, sizeof(message));
        write(client_socket, message, sizeof(message));
        read(client_socket,message, sizeof(message));
        char display_string_2[] = "Server-Side : ";
        write(1, display_string_2, sizeof(display_string_2));
        write(1, message, strlen(message));
    

    	close(client_socket);

    return 0;
}
