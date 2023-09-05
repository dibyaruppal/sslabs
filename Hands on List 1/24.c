/*
============================================================================
Name : 24.c
Author : Dibyarup Pal
Description : Write a program to create a orphan process.
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
		perror("Fork Failed !!\n");
		exit(1);
	}
	else if(child_pid == 0){
		printf("This is Child Process !!\nChild process ID : %d\n",getpid());
		exit(0);
	}
	else{
		printf("This is Parent Process !!\nParent process ID : %d\n",getpid());
		printf("Child process ID : %d\n",child_pid);
	}
	return 0;
}

