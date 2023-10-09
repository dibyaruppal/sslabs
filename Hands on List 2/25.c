/*
============================================================================
Name : 25.c
Author : Dibyarup Pal
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
		a. access permission
		b. uid, gid
		c. time of last message sent and received
		d. time of last change in the message queue
		d. size of the queue
		f. number of messages in the queue
		g. maximum number of bytes allowed
		h. pid of the msgsnd and msgrcv
Date: 7th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<time.h>

int main(){
	int key = ftok("25.c",'a');
	if(key == -1){
		perror("ftok error");
		exit(1);
	}

	int msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid == -1){
		perror("msgget error");
		exit(1);
	}

	struct msqid_ds msq_info;

	if(msgctl(msgid, IPC_STAT, &msq_info) == -1){
		perror("msgctl IPC_STAT error");
		exit(1);
	}

	printf("Access Permission : %o\n", msq_info.msg_perm.mode);
	printf("User ID : %d\n", msq_info.msg_perm.uid);
	printf("Group ID : %d\n", msq_info.msg_perm.gid);
	printf("Time of last Message Sent : %s\n", ctime(&msq_info.msg_stime));
	printf("Time of last Message Received : %s\n", ctime(&msq_info.msg_rtime));
	printf("Time of last Change : %s\n", ctime(&msq_info.msg_ctime));
	printf("Size of the Queue : %lu bytes\n", msq_info.msg_cbytes);
	printf("Number of Messages in the Queue : %lu\n", msq_info.msg_qnum);
	printf("Maximum Number of Bytes Allowed : %lu bytes\n", msq_info.msg_qbytes);
	printf("PID of the Last msgsnd : %d\n", msq_info.msg_lspid);
	printf("PID of the Last msgrcv : %d\n", msq_info.msg_lrpid);
	
	return 0;
}
