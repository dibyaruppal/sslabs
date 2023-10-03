/*
============================================================================
Name : 23.c
Author : Dibyarup Pal
Description : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: 3rd Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	
	long PIPE_BUF, OPEN_MAX;
	PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
	OPEN_MAX = sysconf(_SC_OPEN_MAX);
	printf("PIPE_BUF = %ld\nOPEN_MAX = %ld\n",PIPE_BUF,OPEN_MAX);

	return 0;
}
