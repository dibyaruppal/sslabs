/*
============================================================================
Name : 20.c
Author : Dibyarup Pal
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 3rd Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	
	int fd = open("myfifo",O_WRONLY);
	if(fd == -1){
		perror("open failed");
		exit(1);
	}
	;
	char buff[1024];
	printf("Enter the text to be written into FIFO : ");
	scanf("%[^\n]",buff);
	
	write(fd,&buff,sizeof(buff));

	return 0;
}
