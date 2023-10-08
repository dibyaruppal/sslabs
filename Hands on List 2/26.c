/*
============================================================================
Name : 26.c
Author : Dibyarup Pal
Description : Write a program to send messages to the message queue. Check $ipcs -q
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

	int msgid = msgget(key, IPC_CREAT | 0744);
	if(msgid == -1){
                perror("msgget error");
                exit(1);
        }

	printf("Enter message text : ");
	scanf("%[^\n]s", myq.message);

	printf("Enter message type : ");
        scanf("%ld", &myq.m_type);

	int size = strlen(myq.message);
	int s = msgsnd(msgid, &myq, size + 1, 0);
	if(s==-1){
        	perror("msgsnd error");
               	exit(1);
	}
        printf("Sent message : %s\n", myq.message);
	return 0;
}

