/*
============================================================================
Name : 21.c
Author : Dibyarup Pal
Description : Write a program, call fork and print the parent and child process id.
Date: 1st Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){

	pid_t child_pid;

	child_pid = fork();

	if(child_pid < 0){
		perror("Fork Failed");
		exit(1);
	}
	else if(child_pid == 0){
		printf("Child porcess creation successful !!\nChild Process ID : %d\n",getpid());
		exit (0);
	}
	else{
		printf("This id Parent Process !!\nParent Process ID : %d\n",getpid());
		printf("Child Process ID : %d\n",child_pid);
		wait(NULL);
		exit(0);

	}
	return 0;
}
