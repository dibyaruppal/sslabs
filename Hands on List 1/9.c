/*
============================================================================
Name : 9.c
Author : Dibyarup Pal
Description : Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change
Date: 24th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char* argv[]){
	if(argc!=2)
	{
		printf("Invalid Input !!");
		return 1;
	}
	const char *file_path = argv[1];
	struct stat file_info;
	if(stat(file_path,&file_info)== -1 ){
		perror("Error");
		return 1;
	}

	printf("File information for : %s\n",file_path);
	printf("Inode : %lu\n",(unsigned long) file_info.st_ino);
	printf("Number of Hardlinks : %lu\n",(unsigned long)file_info.st_nlink);
	printf("UID (User ID) : %u\n",file_info.st_uid);
	printf("GID (Group ID) : %u\n",file_info.st_gid);
	printf("Size : %lld bytes\n",(long long) file_info.st_size);
	printf("Block size : %ld bytes\n",(long) file_info.st_blksize);
	printf("Number of blocks : %lld\n",(long long) file_info.st_blocks);
	printf("Time of last access : %s",ctime(&file_info.st_atime));
	printf("Time of last modification : %s",ctime(&file_info.st_mtime));
	printf("Time of last change : %s",ctime(&file_info.st_ctime));
	return 0;
}
