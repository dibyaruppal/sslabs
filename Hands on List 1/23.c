/*
============================================================================
Name : 23.c
Author : Dibyarup Pal
Description : Write a program to create a Zombie state of the running program.
Date: 5th Sept, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	pid_t child_pid;

	child_pid = fork();
	if(child_pid < 0){
		perror("Fork failed !!\n");
		exit(1);
	}
	else if(child_pid == 0){
		printf("Child Process is running !!\nChild process ID - %d\n",getpid());
		exit(0);
	}
	else{
		printf("Parent waiting for child to terminate !!\nParent process ID - %d\n",getpid());
		sleep(30);
		printf("Parent process exiting without waiting for the child !!\n");
		exit(0);
	}
	return 0;
}
