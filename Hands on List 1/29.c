/*
============================================================================
Name : 29.c
Author : Dibyarup Pal
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).
Date: 7th Sept, 2023.
============================================================================
*/

#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>

void print_policy(int policy){
        switch(policy){
        	case SCHED_FIFO:
                	printf("SCHED_FIFO !!\n");
                        break;
                case SCHED_RR:
                        printf("SCHED_RR !!\n");
                        break;
                case SCHED_OTHER:
                        printf("SCHED_OTHER (default) !!\n");
                        break;
                default:
                        printf("Unknown !!\n");
        }
}

int main(){
	int pid = getpid();
	int old_policy, new_policy;
	struct sched_param param;

	old_policy = sched_getscheduler(pid);
	if(old_policy == -1){
		perror("sched_getscheduler");
		exit(1);
	}
	
	printf("Current scheduling policy for PID %d : ",pid);
	print_policy(old_policy);
	
	new_policy = SCHED_FIFO;
	param.sched_priority = 99;
	if(sched_setscheduler(pid, new_policy, &param) == -1){
		perror("sched_setcheduler");
		exit(1);
	}
	
	printf("\nChanged scheduling policy for PID %d to SCHED_FIFO !!\n",pid);

	int updated_policy = sched_getscheduler(pid);
	if(updated_policy == -1){
		perror("sched_getscheduler");
		exit(1);
	}

	printf("Updated scheduling policy for PID %d : ",pid);
	print_policy(updated_policy);

	new_policy = SCHED_RR;
	param.sched_priority = 99;
	if(sched_setscheduler(pid, new_policy, &param) == -1){
		perror("sched_setscheduler");
		exit(1);
	}
	
	printf("\nChanged scheduling policy for PID %d to SCHED_RR !!\n",pid);

	int again_updated_policy = sched_getscheduler(pid);
	if(again_updated_policy == -1){
		perror("sched_getscheduler");
		exit(1);
	}

	printf("Updated scheduling policy for PID %d : ",pid);
	print_policy(again_updated_policy);

	return 0;
}
