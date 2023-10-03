/*
============================================================================
Name : 15.c
Author : Dibyarup Pal
Description : Write a simple program to send some data from parent to the child process.
Date: 1st Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	int pipefd[2];
	char buff[1024];
	
	int p = pipe(pipefd);
	if(p==-1){
		perror("Pipe failed !!\n");
		exit(1);
	}

	int child_pid = fork();

	if(!child_pid){
		close(pipefd[1]);
		int r = read(pipefd[0],&buff,sizeof(buff));
		if(r==-1){
			perror("Read Failed !!\n");
			exit(1);
		}
		int w = write(1,&buff,r);
		if(w==-1){
                        perror("Write Failed !!\n");
                        exit(1);
                }

	}
	else{
		close(pipefd[0]);
		char str[] = "This is a program to send some data from parent to the child process !!\n";
		int w = write(pipefd[1],&str,sizeof(str));
                if(w==-1){
                        perror("Write Failed !!\n");
                        exit(1);
                }
	}
	wait(0);
	
	
	return 0;
}
