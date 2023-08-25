#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){


        int fd = open("ticket_record.txt",O_RDWR | O_CREAT);
        if(fd == -1){
                printf("Error opening file !!\n");
                return 1;
        }

        char input[] = "1";
        
        int fd_wr = write(fd,&input,sizeof(input)-1);
        if(fd_wr == -1){
        	printf("Error writing to file !!\n");
		return 1;	
        }

	return 0;
}
