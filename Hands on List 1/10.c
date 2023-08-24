#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	
	int fd = open("lseekfile.txt",O_RDWR | O_CREAT);
	if(fd == -1){
		printf("Error opening the file !!\n");
		return 1;
	}
	
	char content1[] = "ABCDEFGHIJ";
	char content2[] = "abcdefghij";
	
	int fd_wr = write(fd,content1,sizeof(content1)-1);
	if(fd_wr == -1){
		printf("Error writing the content1 !!\n");
		return 1;
	}

	int lseek_off = lseek(fd,10,SEEK_CUR);
	if(lseek_off == -1){
		printf("Error in lseek operation !!\n");
		return 1;
	}

	int fd_wr2 = write (fd,content2,sizeof(content2)-1);
	if(fd_wr2 == -1){
		printf("Error writing the content2 !!\n");
		return 1;
	}

	printf("lseek offset : %ld\n",(long)lseek_off);

	int fd_close = close(fd);
	if(fd_close == -1){
		printf("Error in closing the file !!\n");
		return 1;
	}

	return 0;
}
