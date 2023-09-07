/*
============================================================================
Name : 27.c
Author : Dibyarup Pal
Description : Write a program to execute ls -Rl by the following system calls
		a. execl
		b. execlp
		c. execle
		d. execv
		e. execvp
Date: 7th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	pid_t child_pid;

	printf("Using execl :\n");
	child_pid = fork();
	if(child_pid < 0 ){
                perror("Fork Failed");
		exit(1);
        }
	else if(child_pid == 0){
		execl("/bin/ls","ls","-Rl",NULL);
		perror("execl");
		exit(1);
	}
	wait(NULL);

	printf("\nUsing execlp :\n");
        child_pid = fork();
	if(child_pid < 0 ){
                perror("Fork Failed");
                exit(1);
        }
	else if(child_pid == 0){
                execlp("ls","ls","-Rl",NULL);
                perror("execlp");
                exit(1);
        }
        wait(NULL);

	printf("\nUsing execle :\n");
        child_pid = fork();
	if(child_pid < 0 ){
                perror("Fork Failed");
                exit(1);
        }
	else if(child_pid == 0){
		char* envp[] ={NULL};
                execle("/bin/ls","ls","-Rl",NULL, envp);
                perror("execle");
                exit(1);
        }
        wait(NULL);

	printf("\nUsing execv :\n");
        child_pid = fork();
	if(child_pid < 0 ){
                perror("Fork Failed");
                exit(1);
        }
	else if(child_pid == 0){
		char* argv[] = {"ls","-Rl", NULL};
                execv("/bin/ls", argv);
                perror("execv");
                exit(1);
        }
        wait(NULL);

	printf("\nUsing execvp :\n");
        child_pid = fork();
	if(child_pid < 0 ){
		perror("Fork Failed");
		exit(1);
	}
	else if(child_pid == 0){
		char* argv[] = {"ls", "-Rl", NULL};
		execvp("ls", argv);
                perror("execvp");
                exit(1);
        }
        wait(NULL);

	return 0;
}

