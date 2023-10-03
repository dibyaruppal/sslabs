/*
============================================================================
Name : 14.c
Author : Dibyarup Pal
Description : Write a simple program to create a pipe, write to the pipe, read from pipe
              and display on the monitor.
Date: 1st Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int pipefd[2];
	char buff[1024];
	int p = pipe(pipefd);
	if(p==-1){
		perror("pipe error\n");
		exit(1);
	}
	char str[] = "Hello World !!\n";
	int w = write(pipefd[1],&str,sizeof(str));
	if(w==-1){
		perror("write failed !!\n");
		exit(1);
	}
	int r = read(pipefd[0],&buff,1024);
	if(r==-1){
		perror("Read faiiled !!\n");
		exit(1);
	}
	write(1,&buff,r);
	
	return 0;
}
