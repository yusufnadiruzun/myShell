#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define _GNU_SOURCE
#define BUFFER_LEN 1024

int main(int argc, char *argv[],char **envp)
{
    char *token;
    char *newargv[10];
    char line[BUFFER_LEN];
    int i =0, j = 0,k,l,f,f2,m,status,temp;
    
      while(1){
          i = 0;
          m = 0;
         printf("myshell>> ");
         fgets(line, BUFFER_LEN,stdin);
         token = strtok(line," ");
           while(token != NULL){
            newargv[i] = token;
            token = strtok(NULL," ");
            i++;
           }
          newargv[i] =NULL;
          
        if(strcmp(line,"exit\n") == 0){
            break;
        }
          
        else if(strcmp(line,"bash\n") == 0){
            f = fork();
            if(f == 0){
                i = execve("/bin/zsh",newargv,envp);
                perror("hata ");
            }
            else{
                l = wait(&status);
            }
        }
        /*
        else if(strcmp(newargv[3],"| islem") == 0 || strcmp(newargv[4],"| tekrar") == 0){
            printf("girdim");
            
            if(f == 0 && (strcmp("islem",newargv[0]) == 0 ||  strcmp("islem",newargv[5]) == 0)){
                f = fork();
                k = execve("islem",newargv,envp);
                perror("hata ");
            }
            
            else{
                l = wait(&status);
            }
        }
         */
         
          
        else if((strcmp(newargv[0],"tekrar")) == 0 && (newargv[1] !=NULL ) && (newargv[2] !=NULL )){
            f = fork();
            if(f == 0){
                k = execve("tekrar",newargv,envp);
                perror("hata ");
            }else{
                l = wait(&status);
            }
            
        }
        
        else if((strcmp(newargv[0],"islem")) == 0 && (newargv[1] !=NULL ) && (newargv[2] !=NULL ) && newargv[3] !=NULL){
            f = fork();
            if(f == 0){
                k = execve("islem",newargv,envp);
                perror("hata ");
            }else{
                l = wait(&status);
            }
        }
           
          
        else if(strcmp(line,"clear\n") == 0){
            system("@cls||clear");
        }
        
        else if(strcmp(line,"ls\n") == 0){
            f = fork();
            if(f == 0){
                k = execv("/bin/ls",argv);
            }
            else{
                l = wait(&status);
            }
        }
        else if(strcmp(newargv[0],"cat") == 0){
            printf("cat : ");
            while(newargv[m] != NULL){
                printf(" %s ", newargv[m]);
                m++;
            }
           
        }
          
        else{
            printf("hatalı komut girdiniz\n");
        }
          
    }
    
}
