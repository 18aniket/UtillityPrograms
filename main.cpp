#include <iostream>

#include <fcntl.h>
#include <zconf.h>
char buffer[2048];

int version =1;


void copy(int oldfd,int newfd);

int main(int argc,char *argv[]){
  int fdOld,fdNew;

  if(argc!=3){
    printf("need 2 arguments \n");
    exit(1);
  }

  fdOld = open(argv[1],O_RDONLY);
  if(fdOld == -1){
    printf("can not open file %s\n",argv[1]);
    exit(1);
  } else{
    printf("opened file %s\n",argv[1]);
  }

  fdNew = creat(argv[2],0666);
      if(fdNew == -1){
        printf("can not create file %s\n",argv[2]);
        exit(1);
      }

      copy(fdOld,fdNew);
      exit(1);

}

void copy(int oldfd,int newfd){
  int count;
  while((count=read(oldfd,buffer, sizeof(buffer)))>0){
    printf("%s\n",buffer);
    write(newfd,buffer,count);
  }

}