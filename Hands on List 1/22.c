/*
Name : 22.c
Author : Dibyarup Pal
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 5th Sept, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
int main(){

	int fd_open = open("processOutput.txt", O_WRONLY | O_CREAT, 0666);
	if(fd_open == -1){
		perror("File Open Failed");
		exit(1);
	}
	char childString[] = "Child Process writes to Output file !!.\n\n";
	char parentString[] = "Parent Process writes to Output file !!.\n";

	pid_t child_pid = fork();

	if(child_pid < 0){
		perror("Fork failed");
		exit(1);
	}
	else if(child_pid ==  0){
		int wr_child = write(fd_open, &childString, sizeof(childString)-1);
		if(wr_child == -1){
			perror("Child process write failed !!");
			exit(1);
		}
		exit(0);
	}
	else{
		int wr_parent = write(fd_open, &parentString, sizeof(parentString)-1);
		if(wr_parent == -1){
			perror("Fork failed");
			exit(1);
		}
		wait(NULL);
		close(fd_open);
		printf("Parent Process to writing to Output file completed !!\n");
	}


	int fd_rd = open("processOutput.txt", O_RDONLY);
	if(fd_rd == -1){
		perror("File open failed for reading");
		exit(1);
	}

	char buffer[256];	

	int rd = read(fd_rd,&buffer,256);
	if(rd == -1){
		perror("Read Failed");
		exit(1);
	}

	int wr = write(1,&buffer,256);
	if(wr == -1){
		perror("Write Failed");
		exit(1);
	}

	close(fd_rd);

	return 0;
}
