//write a c program to calculate the sum of all elements in an array that are greater than the arrays average.

#include<stdio.h>
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    printf("Array is:");
    for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int average=sum/n;
    int greaterSum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>average){
         greaterSum+=arr[i];
        }
    }
   printf("The sum of numbers greater than average value: %d",greaterSum);
   return 0;
}
