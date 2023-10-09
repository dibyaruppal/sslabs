/*
============================================================================
Name : 30.c
Author : Dibyarup Pal
Description : Write a program to create a shared memory.
		a. write some data to the shared memory
		b. attach with O_RDONLY and check whether you are able to overwrite.
		c. detach the shared memory
		d. remove the shared memory
Date: 8th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

int main(){
	int key = ftok(".",'b');
	if(key == -1){
		perror("ftok error");
		exit(1);
	}

	int shmid = shmget(key, 1024, IPC_CREAT | 0744);
	if(shmid == -1){
		perror("shmget error");
		exit(1);
	}

	char* data = shmat(shmid, 0, 0);
	printf("Enter the text : ");
	scanf("%[^\n]s",data);
	printf("Writing into Shared Memory !!\n");
	
	printf("Reading from Shared Memory !!\n");
	char* message = shmat(shmid, 0, 0);
	printf("Text from shared memory : %s\n", message);
	
	getchar();

	printf("Attach the shared memory segement with read-only permission !!\n");
	char* shm_ptr = shmat(shmid, NULL, SHM_RDONLY);
	if(shm_ptr == (char *)-1){
		perror("shmat error");
		exit(1);
	}

	printf("Attemt to overwrite the shared memory failed !!\n");
	strcpy(shm_ptr, "This will not work");
	 
	if(shmdt(shm_ptr) == -1){
		perror("shmdt error");
		exit(1);
	}

	return 0;
}

