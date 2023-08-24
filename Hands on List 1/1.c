#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	int s = symlink("inputfile.txt","inputSymLink");
	if(s<0){
		perror("Failed");
		return 1;
	}	
	int h = link("inputfile.txt","inputHardLink");
	if(h<0){
                perror("Failed");
                return 1;
        }
	int f = mknod("inputFIFO",S_IFIFO,0);
	if(f<0){
		perror("Failed");
		return 1;
	}
	return 0;
}
