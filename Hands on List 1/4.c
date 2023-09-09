/*
============================================================================
Name : 4.c
Author : Dibyarup Pal
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 20th Aug, 2023.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage : %s <filename>\n",argv[0]);
		return 1;
	}

	int fd_open = open(argv[1], O_RDWR | O_EXCL);
	if(fd_open == -1){
		perror("File open failed !!\n");
		return 1;
	}
	printf("Successfully opened File named %s !!\n", argv[1]);

	return 0;
}
