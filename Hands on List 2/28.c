/*
============================================================================
Name : 28.c
Author : Dibyarup Pal
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 8th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>

int main(){
	int key = ftok(".",'a');
	if(key==-1){
		perror("ftok error");
		exit(1);
	}

	int msqid = msgget(key, IPC_CREAT | 0744);
	if(msqid == -1){
		perror("msgget error");
		exit(1);
	}

	struct msqid_ds msq_info;
	
	int m = msgctl(msqid, IPC_STAT, &msq_info);
	if(m == -1){
		perror("msgctl IPC_STAT error");
		exit(1);
	}

	msq_info.msg_perm.mode = 0666;
	int m2 = msgctl(msqid, IPC_SET, &msq_info);
	if(m2 == -1){
		perror("msgctl IPC_SET error");
                exit(1);
	}

	printf("Message queue permissions changed successfully !!\n");

	return 0;
}
