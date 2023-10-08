/*
============================================================================
Name : 27.c
Author : Dibyarup Pal
Description : Write a program to receive messages from the message queue.
		a. with 0 as a flag
		b. with IPC_NOWAIT as a flag
Date: 7th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>

int main(){
	struct msg{
		long int m_type;
		char message[1024];
	} myq;

	int key = ftok(".",'a');
	if(key == -1){
		perror("ftok error");
		exit(1);
	}

	int msgid = msgget(key,0);
	if(msgid == -1){
		perror("msgget error");
		exit(1);
	} 

	printf("Enter Message type : ");
	scanf("%ld",&myq.m_type);

	int rcv = msgrcv(msgid, &myq, sizeof(myq.message), myq.m_type, 0);
        if(rcv == -1){
                perror("msgrcv error");
                exit(1);
        }

	printf("Received Text using 0 as a flag  : %s\n",myq.message);

	return 0;
} 
