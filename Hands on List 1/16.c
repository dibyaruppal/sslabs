#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage: %s <filepath> \n",argv[0]);
		return 1;
	}

	int fd = open(argv[1],O_RDWR | O_CREAT);
	if(fd == -1){
		printf("Error opening file !!\n");
		return 1;
	}

	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();

	if(fcntl(fd, F_SETLKW, &fl) == -1 ){
		printf("Error setting write lock to file !!\n");
		return 1;
	}
	printf("File locked with write lock!!\n");
	sleep(10);
	fl.l_type = F_UNLCK;
	if(fcntl(fd, F_SETLK, &fl) == -1){
		printf("Error ulocking with write !! \n");
		return 1;
	}
	printf("File unlocked from write lock !!\n");
	
	fl.l_type = F_RDLCK;
        if(fcntl(fd, F_SETLKW, &fl) == -1){
                printf("Error locking with read lock !! \n");
                return 1;
	}
        printf("File locked with read lock !!\n");
	sleep(10);

	fl.l_type = F_UNLCK;
        if(fcntl(fd, F_SETLK, &fl) == -1){
                printf("Error ulocking read lock !! \n");
                return 1;
        }
        printf("File unlocked from read lock !!\n");



	return 0;
}
