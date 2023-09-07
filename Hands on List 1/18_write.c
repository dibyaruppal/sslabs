/*
============================================================================
Name : 18.c
Author : Dibyarup Pal
Description : Write a program to perform Record locking.
		a. Implement write lock
Date: 24th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    	int fd = open("record.txt",O_RDWR);
        if(fd==-1){
        	printf("Error opening file\n");
		close(fd);
		return 0;
    	}
    	int x;
    	printf("Enter the record number to access{1,2,3}: ");
    	scanf(" %d",&x);
    	char buff[20];
    	struct flock fl;
    	fl.l_type = F_WRLCK;   
    	fl.l_start = (x-1)*sizeof(buff);
    	fl.l_whence = SEEK_SET;
    	fl.l_len = sizeof(buff); 
    	fl.l_pid = getpid();
    	printf("Waiting outide critical section\n");
    	if(fcntl(fd, F_SETLKW, &fl)==-1){
		printf("Error setting write lock!!\n");
	}
    	printf("Inside the critical section\n");
    	char outstr[]="Record Data: ";
	int wr_out = write(1,&outstr,sizeof(outstr)-1);
	if(wr_out == -1){
		printf("Error writing out string !!\n");
		return 1;
	}
    	int offset  = lseek(fd,(x-1)*sizeof(buff),SEEK_SET);
	if(offset == -1){
		printf("Error setting offset!!\n");
	}
    	int fd_rd = read(fd,&buff,sizeof(buff));
	if(fd_rd ==  -1){
		printf("Error reading character !!\n");
		return 1;
	}
    	write(1,&buff,sizeof(buff));
    	write(1,"\n",2);
    	int i = atoi(buff);
    	char outstr2[] ="Press Enter to increment record";
	int wr_out2 = write(1,&outstr2,sizeof(outstr2)-1);
	if(wr_out2 == -1){
		printf("Error writing out string 2");
		return 1;
	}
    	getchar();
    	getchar();
    	i++;
    	sprintf(buff, "%d", i);
    	char str[]="Current Record number: ";
	write(1,&str,sizeof(str)-1);
    	write(1,&buff,sizeof(buff));
    	write(1,"\n",2);
    	int offset2 = lseek(fd,(x-1)*sizeof(buff),SEEK_SET);
	if(offset2 == -1){
		printf("Error setting 2nd offset !!\n");
	}
    	int fd_wr = write(fd,&buff,sizeof(buff));
	if(fd_wr == -1){
		printf("Error writing charcter !!\n");
		return 1;
	}
	printf("Enter character to go outside of Critical section !!\n");
	getchar();
    	fl.l_type =F_UNLCK;
    	if(fcntl(fd,F_SETLK,&fl)==-1){
		printf("Error unlocking write lock!!\n");
		return 1;
	}
   	char str2[]="Record updated !!\n";
	write(1,&str2,sizeof(str2)-1);
    	close(fd);

    	return 0;
}
