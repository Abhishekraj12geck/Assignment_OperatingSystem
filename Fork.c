#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
int main(){
int arr[30],key1,key2,status;
pid_t p1,p2;
srand(time(NULL));
printf("Array:");
for(int i=0;i<30;i++){
arr[i] = rand()%50+1;
printf(" %d ", arr[i]);
}
printf("\n Enter key1 And key2:");
scanf(" %d %d", &key1, &key2);
//child1
p1=fork(); 
if(p1==0){
for(int i=0;i<=14;i++){
if(arr[i] == key1){
exit(i);  //agar mila to index return karega parent ko key1 ka
}
}
exit(255);// key1 upper nhi milega toh 255 return karega parent ko
}

//parent waits for child1.

waitpid(p1,&status,0); //jab tak child complete na ho  parent  wait karega
int res1=WEXITSTATUS(status); 

if(res1!=255){
printf("key1 present in 1st half process at index :- %d\n",res1);
}
else{
printf("key1 not present in 1st half process\n");
}

//child 2

p2=fork();
if(p2==0){
for(int i=15;i<=29;i++){
if(arr[i] == key2){
exit(i);// parent ko return index value of key2 
}
}
exit(255);// key2 upper nhi milega to parent ko return karega 255.
}

//parent wait for child2

waitpid(p2,&status,0);
int res2=WEXITSTATUS(status);

if(res2!=255){
printf("key2 present in 2nd half process at index :- %d\n",res2);
}
else{
printf("key2 not present in 2nd half process \n");
}
return 0;
}
