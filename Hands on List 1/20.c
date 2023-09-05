/*
============================================================================
Name : 20.c
Author : Dibyarup Pal
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 1st Sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
	int pid = getpid();
	printf("process ID : %d\n",pid);
	int which = PRIO_PROCESS;
	int who = pid;

	printf("Current process priority is %d !!\n",getpriority(which,who));
	int nval = nice(7);
	if(nval == -1){
		printf("Error setting priority using 'nice'\n");
		return 1;
	}
	printf("Current process priority after changing priority is %d !!\n",getpriority(which,who));	
	return 0;
}
