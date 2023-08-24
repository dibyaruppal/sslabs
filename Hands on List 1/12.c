#include<stdio.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Incorrect Input !!\n");
		return 1;
	}

	char *file_path = argv[1];
	int fd = open(file_path,O_RDONLY);
	if(fd == -1){
		printf("Error opening the file !!\n");
		return 1;
	}

	int flags = fcntl(fd,F_GETFL);
	if(flags == -1){
		printf("Error getting file flag !!\n");
		return 1;
	}
	return 0;
}
