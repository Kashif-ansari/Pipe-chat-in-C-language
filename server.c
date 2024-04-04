#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define FIFO_FILE "MYFIFO"
int main(){
int fd;
char* myfifo = "/home/kali/Documents/lab_10/myfifo";
mkfifo(myfifo,0666);
char readbuf1[80],readbuf2[80],readbuf3[80];

while(1){
printf("You can type your message\n");
fd=open(myfifo,O_CREAT|O_WRONLY);
fgets(readbuf3,80,stdin);
write(fd,readbuf3,strlen(readbuf3)+1);
close(fd);

fd=open(myfifo,O_RDONLY);
read(fd,readbuf1,sizeof(readbuf1));
printf("Read Client Message %s\n",readbuf1);
read(fd,readbuf2,sizeof(readbuf2));
printf("Read Kashif Message %s\n",readbuf2);

close(fd);
}
return 0;
}

