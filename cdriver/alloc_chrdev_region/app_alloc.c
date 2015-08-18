#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

main(){
char *mybuf="leela naresh";
int fd=open("/dev/alloc_naresh",O_RDWR);
	if(fd<0){
		printf("error in opening a file\n");
		exit(11);
	}	
      	if(write(fd,mybuf,12)){
		printf("error in opening a file\n");	
	}
	printf("written successfully");
close(fd);	
}
