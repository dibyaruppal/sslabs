/*
============================================================================
Name : 15.c
Author : Dibyarup Pal
Description : Write a program to display the environmental variable of the user (use environ).
Date: 24th Aug, 2023.
============================================================================
*/

#include<stdio.h>

extern char **environ;

int main(){
	for(char **env = environ; *env!=NULL; env++)
		printf("%s\n",*env);
	return 0;
}
