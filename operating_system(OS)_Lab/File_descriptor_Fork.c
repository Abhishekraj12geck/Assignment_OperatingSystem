//Question 2: File Reading by Child Process
//Problem Statement:
//Write a C program that demonstrates how data can be passed from a parent process to a child process
//using the file system. The parent will act as the ”Writer” and the child will act as the ”Reader.”
//Functional Requirements:
//a) Parent Process:
//• Create a file named data.txt using open() with flags O CREAT | O WRONLY | O TRUNC.
//• Prompt the user to enter a message (use fgets for space support).
//• Write the input string into the file and ensure the file is closed or synchronized before the
//child begins reading.
//• Use wait() to ensure the child finishes its display task before the parent terminates.
//b) Child Process:
//• Use fork() to create the child process.
//• Open data.txt in O RDONLY mode.
//• Use the read() system call to pull the data into a local buffer.
//• Print the contents to the standard output (terminal).


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
int main(){
int fd;
char child_msg[100];
fd=open("data.txt",O_CREAT | O_WRONLY |O_TRUNC,0644);

if(fd<0){
perror("file not open");
exit(1);
}

printf("Enter text to write into file:");
fgets(child_msg,sizeof(child_msg),stdin);
write(fd,child_msg,strlen(child_msg));
close(fd);

pid_t pid=fork();

if(pid<0){
printf("fork not create");
exit(1);
}

//write child logic
else if(pid==0){

char read_child_msg[100];   //data.txt me jo text hai wo is character variable me store ho jayega 
fd=open("data.txt",O_RDONLY);

if(fd<0){
perror("file  open failed ");
exit(1);
}

read(fd,read_child_msg,sizeof(read_child_msg));
printf("\n\n%s",read_child_msg);
close(fd);
//exit(0);
}

//write parent logic
else
{
sleep(1);//1 means 1 second ke liye sleep parents ko
//wait(NULL);
}
return 0;
}

