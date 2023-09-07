/*
============================================================================
Name : 6.c
Author : Dibyarup Pal
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 24th Aug, 2023.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main(){
	int buffer[1];
	while(1){
		int fd_read = read(STDIN_FILENO,&buffer,1);
		if(fd_read==0) break;
		if(fd_read<0) {
			perror("Failed");
			return 1;
		}
		int fd_write = write(STDOUT_FILENO,&buffer,1);
		if(fd_write<0){
			perror("Failed");
			return 1;
		}
	}		
	return 0;
}
