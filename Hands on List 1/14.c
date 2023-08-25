#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    	if (argc != 2) {
        	printf("Usage: %s <file_path>\n", argv[0]);
        	return 1;
    	}

    	const char *file_path = argv[1];
    	struct stat file_info;

    	if (stat(file_path, &file_info) == -1) {
        	perror("Error");
        	return 1;
    	}

    	if (S_ISREG(file_info.st_mode))
        	printf("Regular file: %s\n", file_path);
	else if (S_ISDIR(file_info.st_mode))
        	printf("Directory: %s\n", file_path);
	else if (S_ISCHR(file_info.st_mode)) 
        	printf("Character special file: %s\n", file_path);
	else if (S_ISBLK(file_info.st_mode))
        	printf("Block special file: %s\n", file_path);
	else if (S_ISFIFO(file_info.st_mode))
        	printf("FIFO (named pipe): %s\n", file_path);
	else if (S_ISLNK(file_info.st_mode))
        	printf("Symbolic link: %s\n", file_path);
	else if (S_ISSOCK(file_info.st_mode))
        	printf("Socket: %s\n", file_path);
	else 
        	printf("Unknown file type: %s\n", file_path);

    return 0;
}

