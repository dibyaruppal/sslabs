/*
============================================================================
Name : 24.c
Author : Dibyarup Pal
Description : Write a program to create a message queue and print the key and message queue id.
Date: 7th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

int main(){
	int key = ftok(".",'a');
	if(key == -1){
		perror("ftok error");
		exit(1);
	}
	int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0744);
	if(msgid == -1){
                perror("msgget error");
                exit(1);
        }
	printf("Key : 0x%0x\nmsgid : %d\n", key, msgid);
	return 0;
}
