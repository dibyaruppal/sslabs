/*
============================================================================
Name : 29.c
Author : Dibyarup Pal
Description : Write a program to remove the message queue.
Date: 8th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>

int main(){
	int key = ftok(".",'a');
	if(key == -1){
		perror("ftok error");
		exit(1);
	}

	int msqid = msgget(key , 0666);
	if(msqid == -1){
		perror("msgget error");
		exit(1);
	}

	if(msgctl(msqid, IPC_RMID, NULL) == -1){
		perror("msgctl IPC_RMID");
		exit(1);
	}

	printf("Message queue removed Successfully !!\n");
	return 0;
}
