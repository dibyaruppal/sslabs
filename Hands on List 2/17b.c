/*
============================================================================
Name : 17.c
Author : Dibyarup Pal
Description : Write a program to execute ls -l | wc.
		a. use dup
		b. use dup2
		c. use fcntl
Date: 2nd Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
	int pipefd[2];
	int p = pipe(pipefd);
	if(p==-1){
		perror("Pipe Error !!\n");
		exit(1);
	}	

	if(!fork()){
		close(pipefd[0]);
		dup2(pipefd[1],1);
		execl("/bin/ls","ls","-l",NULL);	
	}
	else{	
		close(pipefd[1]);
		dup2(pipefd[0],0);
		execl("/bin/wc","wc",NULL);
	}

	return 0;
}
