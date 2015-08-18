#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
//main(){
//char buff="leela naresh";
//int fd;
//fd=open("/dev/chr_reg",O_RDWR);
//	if(fd<0){
//		printf("error in opening a file\n");
//	}
//if(write(fd,buff,12)<0){
//	printf("error in writing a file\n");
//}
//close(fd);
//}
main(){
char *mybuf="leela naresh";
int fd=open("/dev/chr_reg",O_RDWR);
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

