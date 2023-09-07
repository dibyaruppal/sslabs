/*
============================================================================
Name : 5.c
Author : Dibyarup Pal
Description : Write a program to create five new files with infinite loop. Execute the program
	      in the background and check the file descriptor table at /proc/pid/fd.
Date: 24th Aug, 2023.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<string.h>
int main(){	
	mode_t mode = S_IWUSR;
	int fd_1 = creat("newfile1.txt",mode);
	int fd_2 = creat("newfile2.txt",mode);
	int fd_3 = creat("newfile3.txt",mode);
	int fd_4 = creat("newfile4.txt",mode);
	int fd_5 = creat("newfile5.txt",mode);
	if(fd_1 == -1 && fd_2 == -1 && fd_3 == -1 && fd_4 == -1 && fd_5 == -1)
	{
		printf("Unsuccessful file creation !!\n");
		return 1;
	}
	while(1){};
	return 0;
}
