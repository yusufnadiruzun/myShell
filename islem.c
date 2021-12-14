#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[],char ** envp){
    int k,f,status,l;
    
    if(strcmp(argv[1],"topla") == 0 ){
        f = fork();
        if(f == 0){
            k = execve("topla",argv,envp);
            perror("hata ");
        }else{
            l = wait(&status);
        }
    }
    else if(strcmp(argv[1],"cikar") == 0 ){
        f = fork();
        if(f == 0){
            k = execve("cikar",argv,envp);
            perror("hata ");
        }else{
            l = wait(&status);
        }
    }
}
