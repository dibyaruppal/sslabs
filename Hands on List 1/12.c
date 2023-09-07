/*
============================================================================
Name : 12.c
Author : Dibyarup Pal
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 24th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Incorrect Input !!\n");
		return 1;
	}

	char *file_path = argv[1];
	int fd = open(file_path,O_WRONLY);
	if(fd == -1){
		printf("Error opening the file !!\n");
		return 1;
	}

	int flags = fcntl(fd,F_GETFL);
	if(flags == -1){
		printf("Error getting file flag !!\n");
		return 1;
	}
	printf("Flag value : %d\n",flags);

	// check the file access mode using the flags
	int access_mode = flags & O_ACCMODE;

	if(access_mode == O_RDONLY)
		printf("File '%s' is opened in READ-ONLY mode !!\n", file_path);
	else if(access_mode == O_WRONLY)
		printf("File '%s' is opened in WRITE-ONLY mode !!\n",file_path);
	else if(access_mode == O_RDWR)
		printf("File '%s' is opened in READ-WRITE mode !!\n", file_path);
	else
		printf("Unknown access mode for file '%s' !!\n", file_path);

	return 0;
}
