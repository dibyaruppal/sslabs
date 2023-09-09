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
		printf("This is Child Process before sleep!!\nChild process ID : %d\n",getpid());
		sleep(3);
		printf("This is Child Process after sleep!!\nChild process ID : %d\n",getpid());
	}
	else{
		printf("This is Parent Process !!\nParent process ID : %d\n",getpid());
		exit(0);
	}
	return 0;
}

