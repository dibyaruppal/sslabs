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

	printf("Attach the shared memory segement !!\n");
        char* shm_ptr = shmat(shmid, NULL, SHM_RND);
        if(shm_ptr == (char *)-1){
                perror("shmat error");
                exit(1);
        }

        if(shmdt(shm_ptr) == -1){
                perror("shmdt error");
                exit(1);
        }

        printf("Shared Memory Detached !!\n");

        if(shmctl(shmid, IPC_RMID, NULL)== -1){
                perror("shmctl IPC_RMID error");
                exit(1);
        }

        printf("Shared memory segment removed successfully !!\n");

        return 0;
}

