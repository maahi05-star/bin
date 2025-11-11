#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>   /* for getpid()*/
#include<sys/wait.h>    /*it is for 'wait'*/
pid_t num_pid;
void asc(int a[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
        int temp = a[j];
        a[j]=a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
void desc(int a[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]<a[j+1]){
        int temp = a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}
void display(int a[], int n){
  for(int i=0;i<n;i++){
    printf("%d\n", a[i]);
  }
  exit(0);
}
void main(){
  int n=5;
  int a[5] = {5,7,8,1,2};
  num_pid = fork();
  if(num_pid <0){
    printf("Error in fork execution\n");
  }
  else{
    if(num_pid == 0){
      printf("this is the child process id %d , descending order :\n",getpid());
      desc(a ,n);
      display(a,n);
      }
    else {
      printf("this is parent process id %d\n",getpid());
      asc(a,n);
      display(a,n);
      wait(NULL);
      }
  }
  exit(0);
}
