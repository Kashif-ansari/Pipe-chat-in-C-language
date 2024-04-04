#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#define FIFO_FILE "MYFIFO"
int main(){
int fd2;
char* myfifo = "/home/kali/Documents/lab_10/myfifo";
mkfifo(myfifo,0666);
char readbuf1[80],readbuf2[80],readbuf3[80];
while(1){
printf("You can type your message\n");
fd2=open(myfifo,O_CREAT|O_WRONLY);
fgets(readbuf1,80,stdin);
write(fd2,readbuf1,strlen(readbuf1)+1);
close(fd2);
fd2=open(myfifo,O_RDONLY);
read(fd2,readbuf2,sizeof(readbuf2));
printf("Read Kashif Message %s\n",readbuf2);
read(fd2,readbuf3,sizeof(readbuf3));
printf("Read Server Message %s\n",readbuf3);
close(fd2);}
return 0;}