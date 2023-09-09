/*
============================================================================
Name : 1.c
Author : Dibyarup Pal
Description : Create the following types of a files using (i) shell command (ii) system call
		a. soft link (symlink system call)
		b. hard link (link system call)
		c. FIFO (mkfifo Library Function or mknod system call).
Date: 18th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	int s = symlink("inputfile.txt","inputSymLink");
	if(s<0){
		perror("Failed");
		return 1;
	}	
	int h = link("inputfile.txt","inputHardLink");
	if(h<0){
                perror("Failed");
                return 1;
        }
	int f = mknod("inputFIFO",S_IFIFO,0);
	if(f<0){
		perror("Failed");
		return 1;
	}
	return 0;
}
