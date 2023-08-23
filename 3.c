#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(){
	int fd_create = creat("ofile.txt", O_RDWR);
	if(fd_create==-1)
		printf("File creation unsuccessfull !!");
	else
		printf("File created successfully !!");
	return 0;
}
