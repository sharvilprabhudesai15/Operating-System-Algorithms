//Programmer Name : Sharvil Prabhudesai 20co41
//Program Title : Use of fork() and display whether it is a parent or child process
#include<stdio.h>
int main(){
    int pid;
    pid = fork();
    if( pid < 0){
        printf("Error : Cannot Process  \n");
        exit(1);
    }
    if( pid == 0){
        printf("Child Process \n");
        exit(0);
    }
    else {
        printf("Parent Process \n");

    }
    return 0;
}
