#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define FIFO_FILE "MYFIFO"
int main(){
int fd1;

char* myfifo = "/home/kali/Documents/lab_10/myfifo";
mkfifo(myfifo,0666);
char readbuf1[80],readbuf2[80],readbuf3[80];

while(1){
printf("You can type your message\n");
fd1=open(myfifo,O_CREAT|O_WRONLY);
fgets(readbuf2,80,stdin);
write(fd1,readbuf2,strlen(readbuf2)+1);
close(fd1);

fd1=open(myfifo,O_RDONLY);
read(fd1,readbuf1,sizeof(readbuf1));
printf("Read Client Message %s\n",readbuf1);
read(fd1,readbuf3,sizeof(readbuf3));
printf("Read Server Message %s\n",readbuf3);

close(fd1);
}
return 0;
}

