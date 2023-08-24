#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("Wrong input size !!");
		return 1;
	}
	int buffer[1];
	int fd_rd = open(argv[1],O_RDONLY);
	if(fd_rd<0){
		printf("File open unsuccessful !!");
		return 1;	
	}
	while(1){
		int rd_char = read(fd_rd,&buffer,1);
		if(rd_char==0)
			break;
		if(rd_char<0)
		{
			printf("Unsuccessful read !!");
			return 1;
		}
		int wr_char = write(STDOUT_FILENO,&buffer,1);
		if(wr_char<0)
		{
			printf("Unsuccessful write !!");
			return 1;
		}
	}
	int close_fd_rd = close(fd_rd);
	return 0;
}
