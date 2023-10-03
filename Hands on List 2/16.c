/*
============================================================================
Name : 16.c
Author : Dibyarup Pal
Description : Write a program to send and receive data from parent to child vice versa.
              Use two way communication.
Date: 2nd Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int pipe1fd[2],pipe2fd[2];

	int p1 = pipe(pipe1fd);
	int p2 = pipe(pipe2fd);
        if(p1 == -1 || p2 == -1){
                perror("Pipe Error !!\n");
                exit(1);
        }

	if(!fork()){
		close(pipe1fd[0]);
		close(pipe2fd[1]);

		char write_in_pipe_1[] = "Child is writing in Pipe 1 in Writing end of pipe 1 !!\n";
		int w = write(pipe1fd[1],&write_in_pipe_1,sizeof(write_in_pipe_1));
		if(w==-1){
			perror("Write Failed in Child !!\n");
			exit(1);
		}
		
		char read_from_pipe_2[1024];
                int r = read(pipe2fd[0],&read_from_pipe_2,sizeof(read_from_pipe_2));
                if(r==-1){
                        perror("Read Failed in Child !!\n");
                        exit(1);
                }
                char pf[] = "Child is reading from pipe 2 from reading end of pipe 2 !!\n";
                write(1,&pf,sizeof(pf));
                write(1,&read_from_pipe_2,r);
                write(1,"\n",1);
	}
	else{
		close(pipe1fd[1]);
		close(pipe2fd[0]);
		
		char read_from_pipe_1[1024];
		int r = read(pipe1fd[0],&read_from_pipe_1,sizeof(read_from_pipe_1));
		if(r==-1){
			perror("Read Failed in Parent !!\n");
			exit(1);
		}
		char pf[] = "Parent is reading from pipe 1 from reading end of pipe 1 !!\n";
		write(1,&pf,sizeof(pf));
		write(1,&read_from_pipe_1,r);
		write(1,"\n",1);
		
		char write_in_pipe_2[] = "Parent is writing in Pipe 2 in Writing end of pipe 2 !!\n";
		int w = write(pipe2fd[1],&write_in_pipe_2,sizeof(write_in_pipe_2));
                if(w==-1){
                        perror("Write Failed in Parent !!\n");
                        exit(1);
                }

	}

	return 0;
}
