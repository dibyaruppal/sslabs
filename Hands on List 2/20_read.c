/*
============================================================================
Name : 20.c
Author : Dibyarup Pal
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 3rd Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	int fd = open("myfifo",	O_RDONLY);
	if(fd ==-1){
		perror("open failed");
		exit(1);
	}
	
	char buff[1024];
	
	read(fd,&buff,sizeof(buff));

	printf("The string entered into FIFO file : %s\n",buff);

	return 0;
}
