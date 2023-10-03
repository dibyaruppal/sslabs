/*
============================================================================
Name : 19.c
Author : Dibyarup Pal
Description : Create a FIFO file by
		a. mknod command
		b. mkfifo command
		c. use strace command to find out, which command (mknod or mkfifo) is better.
		c. mknod system call
		d. mkfifo library function
Date: 3rd Oct, 2023.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>

int main(){
	int m = mknod("fifo_mknod",S_IFIFO|0744,0);
	if(m == -1){
		perror("mknod error !!\n");
		exit(1);
	}

	int f = mkfifo("fifo_mkfifo",0744);
	if(f==-1){
		perror("mkfifo error !!\n");
		exit(1);
	}

	return 0;
}
