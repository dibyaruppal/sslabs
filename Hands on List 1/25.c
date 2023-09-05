/*
============================================================================
Name : 25.c
Author : Dibyarup Pal
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 5th Sept, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	pid_t child_pid[3];
	int wstatus;
	for(int i=0;i<3;i++){
		child_pid[i] = fork();
		if(child_pid[i] < 0){
			perror("Fork Error");
			exit(1);
		}
		else if(child_pid[i] == 0){
			printf("Child %d (PID - %d) is Running !!\n",i+1,getpid());
			//sleep(2);
			exit(0);
		}
	}

	printf("Parent (PID : %d) is waiting for child 2 (PID : %d) to finish !!\n", getpid(), child_pid[1]);

	pid_t terminated_pid = waitpid(child_pid[1], &wstatus, 0);

	if(terminated_pid == -1){
		perror("waitpid failed");
		exit(1);
	}

	if (WIFEXITED(wstatus))
		printf("Process (PID : %d) has exited normally with status %d !!\n",child_pid[1],WIFEXITED(wstatus));
	else
		printf("Process (PID : %d) has not exited normally !!\n", child_pid[1]);

	return 0;
}
