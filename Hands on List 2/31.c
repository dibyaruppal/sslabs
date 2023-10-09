/*
============================================================================
Name : 31.c
Author : Dibyarup Pal
Description : Write a program to create a semaphore and initialize value to the semaphore.
		a. create a binary semaphore
		b. create a counting semaphore
Date: 8th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<sys/ipc.h>

int main(){
	union semun {
		int val;
		struct semid_ds *buf;
		unsigned short int *array;
	};

	// Creating Binary semaphore
	union semun binary_semaphore;
	
	int key = ftok("31.c",'a');
	if(key == -1){
		perror("ftok error");
		exit(1);
	}

	int semid = semget(key, 1, IPC_CREAT | 0644);
	if(semid == -1){
		perror("semget error");
                exit(1);
	}
	binary_semaphore.val = 1;
	if(semctl(semid,0,SETVAL,binary_semaphore) == -1){
		perror("semctl error");
		exit(1);
	}

	printf("Created Binary Semaphore !!\n");

	// Creating Counting Semaphore
	union semun counting_semaphore;

        int key_count = ftok("31.c",'b');
        if(key_count == -1){
                perror("ftok error");
                exit(1);
        }

        int semid_count = semget(key_count, 1, IPC_CREAT | 0666);
        if(semid_count == -1){
                perror("semget error");
                exit(1);
        }
        counting_semaphore.val = 5;
        if(semctl(semid_count,0,SETVAL, counting_semaphore) == -1){
                perror("semctl error");
                exit(1);
        }

        printf("Created Conunting Semaphore !!\n");
	return 0;
}
