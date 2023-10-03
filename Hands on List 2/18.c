/*
============================================================================
Name : 18.c
Author : Dibyarup Pal
Description : Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2.
Date: 3rd Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int pipe1fd[2],pipe2fd[2];
	int p1 = pipe(pipe1fd);
	int p2 = pipe(pipe2fd);
	if(p1==-1 || p2 == -1){
		perror("Pipe failed !!\n");
		exit(1);
	}

	if(!fork()){
		close(pipe2fd[0]);
		close(pipe2fd[1]);
		close(pipe1fd[0]);

		dup2(pipe1fd[1],1);

		execlp("ls","ls","-l",NULL);
	}
	else{
		if(!fork()){
			close(pipe1fd[1]);
			close(pipe2fd[0]);
			
			
			dup2(pipe1fd[0],0);
			dup2(pipe2fd[1],1);

			execlp("grep","grep","^d",NULL);
		}
		else{
			close(pipe1fd[0]);
                	close(pipe1fd[1]);
                	close(pipe2fd[1]);

			dup2(pipe2fd[0],0);

			execlp("wc","wc",NULL);
		}
	
	}
	return 0;
}
