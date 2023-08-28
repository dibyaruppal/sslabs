#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int fd = open("record.txt",O_RDWR);
        if(fd==-1){
        	printf("Error opening file\n");
		close(fd);
		return 0;
    	}
    	int x;
	char inputstr[] ="Enter the record number to access{1,2,3}: ";
    	int wr = write(1,&inputstr,sizeof(inputstr)-1);
	if(wr == -1){
		printf("Error input str!\n");
		return 1;
	}
    	scanf(" %d",&x);
    	char buff[20];
    	struct flock fl;
    	fl.l_type = F_RDLCK;   
    	fl.l_start = (x-1)*sizeof(buff);
    	fl.l_whence = SEEK_SET;
    	fl.l_len = sizeof(buff); 
    	fl.l_pid = getpid();
    	printf("Waiting outside critical section !!\n");
    	if(fcntl(fd, F_SETLKW, &fl)==-1){
		printf("Error setting read lock 1!\n");
		return 1;
	}
    	printf("Inside the critical section\n");
	char istr[]="Record Data : ";
    	int wr2 = write(1,&istr,sizeof(istr)-1);
	if(wr2 == -1){
		printf("Error writing ");
	}
    	int offset = lseek(fd,(x-1)*sizeof(buff),SEEK_SET);
	if(offset == -1){
		printf("Error setting offset to currect position !!\n");
		return 1;
	}	
    	int rd = read(fd,&buff,sizeof(buff));
	if(rd == -1){
		printf("Error reading file !!\n");
		return 1;
	}
    	int wr3 = write(1,&buff,sizeof(buff));
	if(wr3 == -1){
		printf("Error writing to file!!\n");
		return 1;
	}
    	getchar();
    	getchar();
	printf("\nEnter character to unlock !!\n");
    	fl.l_type =F_UNLCK;
    	if(fcntl(fd,F_SETLK,&fl)==-1){
		printf("Error unlocking read lock !!\n");
		return 1;
	}
    	printf("Outside read lock !!\n");
    	close(fd);

	return 0;
}
