/*
============================================================================
Name : 22.c
Author : Dibyarup Pal
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 14th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/select.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	fd_set rfds;

	struct timeval tv;
	char buff[1024];
	
	int fifoStatus; 
	char *fifoName = "./22-myfifo";
	
    	//fifoStatus = mkfifo(fifoName, S_IRWXU);
    	//if (fifoStatus == -1){
        //	perror("Error while creating FIFO file fifoOne");
	//	exit(1);
	//}

	int fd = open(fifoName, O_NONBLOCK | O_RDONLY);

	if(fd == -1){
		perror("open failed");
		exit(1);
	}

	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

	tv.tv_sec = 10;
        tv.tv_usec = 0;

	int retval = select(fd+1, &rfds, NULL, NULL, &tv);
	printf("retval : %d\n",retval);
	if(retval == -1){
		perror("select error ");
		exit(1);
	}
	else if(retval){
		
		int r = read(fd,&buff,sizeof(buff));
		if(r == -1){
                	perror("read failed");
                	exit(1);
		}
		printf("The data entered into FIFO file : %s\n",buff);
	}
	else
		printf("No data is available for reading within 10 sec !!\n");
	
	close(fd);
	return 0;
}
