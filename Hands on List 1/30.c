/*
============================================================================
Name : 30.c
Author : Dibyarup Pal
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int h,m,s;
	time_t time_input , time_curr;
	struct tm *time_info;

	char inputstr[] = "Enter the time at which you want to execute the program in 24 hours format(hh:mm:ss) : ";
        write(1,&inputstr,sizeof(inputstr)-1);
        scanf("%d:%d:%d",&h,&m,&s);
		
	pid_t child_pid;
	child_pid = fork();
	
	time(&time_curr);
        time_info = localtime(&time_curr);
        time_info->tm_hour = h;
        time_info->tm_min = m;
        time_info->tm_sec = s;

        time_input = mktime(time_info);

        int sleep_time = difftime(time_input,time_curr);
        
	if(child_pid < 0){
		perror("Fork Failed !!\n");
		exit(1);
	}
	if(child_pid == 0){
		setsid();
		umask(0);
	
		sleep(sleep_time);
		
		if(execl("/bin/cat", "cat", "/media/dibyaruppal/New Volume/IIITB/1st_sem/sslabs/Hands on List 1/inputfile.txt", NULL) == -1){
			perror("execl failed");
			exit(1);
		}
		exit(0);
	}
	else
		exit(0);
	return 0;
}
