/*
============================================================================
Name : 22.c
Author : Dibyarup Pal
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 3rd Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/select.h>

int main(){
	fd_set rfds;

	struct timeval tv;
	tv.tv_sec = 10;
	tv.tv_usec = 0;

	char buff[1024];

	int fd = open("myfifo", O_RDONLY|O_WRONLY);
	if(fd == -1){
		perror("open failed");
		exit(1);
	}

	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

	//printf("Enter text within 10 seconds :\n");

	int retval = select(fd+1, &rfds, NULL, NULL, &tv);
	if(retval == -1){
		perror("select()");
		exit(1);
	}
	else if(retval){
		printf("Data is available for reading within 10 sec !!\n");
		int r = read(fd,buff,sizeof(buff));
		if(r == -1){
                	perror("read failed");
                	exit(1);
		}
		printf("The data entered into FIFO file : %s\n",buff);
	}
	else
		printf("No data is available for reading within 10 sec !!\n");

	return 0;
}
