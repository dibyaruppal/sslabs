/*
============================================================================
Name : 18.c
Author : Dibyarup Pal
Description : Write a program to perform Record locking. (Part I - initialisation)
		a. Implement write lock
		b. Implement read lock
	      Create three records in a file. Whenever you access a particular record,
	      first lock it then modify/access to avoid race condition.
Date: 28th Aug, 2023.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    	int fd = open("record.txt",O_WRONLY | O_CREAT);
        if(fd==-1){
        	printf("Error opening file!!\n");
		close(fd);
		return 1;
    	}
	

    	char buff[20];
    	for(int i=0;i<3;i++){
        	int off = lseek(fd,i*sizeof(buff),SEEK_SET);
		if(off == -1){
			printf("Error lseek");
			return 1;
		}
  		char inputstr[]="Enter Integer : ";
		int wr = write(1,&inputstr,sizeof(inputstr)-1);
		if(wr == -1){
			printf("Error taking input \n");
			return 1;
		}

        	int rd_char = read(0,&buff,sizeof(buff));
		if(rd_char == -1){
                        printf("Error reading value !!\n");
                        return 1;
                }

        	int wr_char = write(fd,&buff,sizeof(buff));
		if(wr_char == -1){
                        printf("Error writing to fd !!\n");
                        return 1;
                }
    	}
    	int fd_close = close(fd);
	return(0);
}
