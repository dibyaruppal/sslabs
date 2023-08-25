#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = open("dup_test.txt",O_RDWR | O_CREAT);
	if(fd == -1){
		printf("Error opening dup_test.txt || \n");
		return 1;
	}
	printf("fd -> %d\n",fd);

	char content1[] = "1. Hello World !!\n";
	int fd_wr = write(fd,content1,sizeof(content1)-1);
	if(fd_wr == -1){
		printf("Error writing to dup_test.txt\n");
		close(fd);
		return 1;
	}

	int dup_fd = dup(fd);
	if(dup_fd == -1){
		printf("Error duplicating using dup system call !!\n");
		close(fd);
		return 1;
	}
	printf("dup_fd -> %d\n",dup_fd);

	char content2[] = "2. Hello World !!\n";
	int dup_fd_wr = write(dup_fd,content2,sizeof(content2)-1);
	if(dup_fd_wr == -1){
		printf("Error writing content2 in dup_test.txt !!\n");
		close(fd);
		close(dup_fd);
		return 1;
	}

	int new_fd = open("dup2_test.txt",O_RDWR | O_CREAT);
	if(new_fd == -1){
		printf("Error opening dup2_test.txt");
		close(fd);
		close(dup_fd);
		return 1;
	}
	printf("new_fd -> %d\n",new_fd);
	
	if(dup2(dup_fd,new_fd) == -1){
		printf("Error duplicating using dup2 !!\n");
		close(fd);
		close(dup_fd);
		close(new_fd);
		return 1;
	}
	printf("new_fd -> %d\n",new_fd);

	char content3[] = "3. Hello World !!\n";
	int dup2_fd_wr = write(new_fd,content3,sizeof(content3)-1);
	if(dup2_fd_wr == -1){
		printf("Error writing content3 to dup2_test.txt");
		close(fd);
		close(dup_fd);
		close(new_fd);
		return 1;
	}

	close(fd);
	close(dup_fd);
	close(new_fd);

	return 0;
}
