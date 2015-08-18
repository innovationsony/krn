#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
main(){
int fd;
char *my_buf="leela naresh";
fd=open("/dev/aug12",O_RDWR);
if(fd<0){
	printf("error in opening a file\n");
	exit(10);
}
if(write(fd,my_buf,12)<0){
	printf("error in writing a file\n");	
}
close(fd);

}
