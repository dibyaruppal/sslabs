/*
============================================================================
Name : 17.c
Author : Dibyarup Pal
Description : Write a program to simulate online ticket reservation.
	      Write a separate program, to open the file, implement write lock, read the ticket number,
	      increment the number and print the new ticket number then close the file.(Part II)
Date: 24th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void acquire_write_lock(int fd){
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	if(fcntl(fd, F_SETLKW,&fl)==-1){
		printf("Error setting write lock !!\n");
	}
	printf("Inside Write lock !!\n");
}

void release_write_lock(int fd){
	struct flock fl;
        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fl.l_pid = getpid();
        if(fcntl(fd,F_SETLK,&fl)==-1){
                printf("Error releasing write lock !!\n");
        }
        printf("Outside Write lock !!\n");
}

int main(){
	char buf[256];
	int fd = open("ticket_record.txt",O_RDWR);
	if(fd==-1){
		printf("Error opening file !!\n");
		return 1;
	}
	
	int rd_char = read(fd,&buf,256);
	if(rd_char == -1){
		printf("Error opening file !!\n");
                return 1;
	}
	printf("Waiting outside Critical section !!\n");
	acquire_write_lock(fd);

	int val = atoi(buf)+1;
	sprintf(buf,"%d",val);
	
	int offset = lseek(fd,0,SEEK_SET);
	if(offset == -1){
		printf("Error setting offset to zero !!\n");
		return 1;
	}

	int wr_char = write(fd,&buf,256);
	if(wr_char == -1){
		printf("Error writing inside write lock!!\n");
		return 1;
	}

	printf("Your ticket Number : %d\n",val);
	getchar();
	release_write_lock(fd);
	
	close(fd);

	return 0;
}
