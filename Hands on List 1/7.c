/*
============================================================================
Name : 7.c
Author : Dibyarup Pal
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 24th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if(argc !=3){
		printf("Incorrect Input !!!");
	}
	int fd_rd = open(argv[1], O_RDONLY);
	int fd_wr = open(argv[2], O_WRONLY | O_CREAT);

	if(fd_rd==-1 || fd_wr==-1){
		printf("Unable to open file!!");
	}	

	while(1){
		char buff;
		int rd_char = read(fd_rd,&buff,1);
		if(rd_char==0)
			break;
		int wr_char = write(fd_wr,&buff,1);

	}
	int close_fd_rd = close(fd_rd);
	int close_fd_wr = close(fd_wr);

	return 0;
}
