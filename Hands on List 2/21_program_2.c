/*
============================================================================
Name : 21.c
Author : Dibyarup Pal
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 3rd Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
        int fifo1fd = open("fifo1", O_RDONLY);
        int fifo2fd = open("fifo2", O_WRONLY);

        if(fifo1fd == -1 || fifo2fd == -1){
                perror("open failed");
                exit(1);
        }

        char buff1[1024], buff2[1024];

        printf("Enter the text to written in FIFO file 2 : ");
        scanf("%[^\n]",buff2);

	int w = write(fifo2fd,buff2,sizeof(buff2));
        if(w == -1){
                perror("write failed");
                exit(1);
        }

        int r = read(fifo1fd,&buff1,sizeof(buff1));
	if(r == -1){
                perror("read failed");
                exit(1);
        }

        printf("The string entered into FIFO file 1 : %s\n", buff1);

        return 0;
}
