#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int i;
    int counter = atoi(argv[2]);
    for(i = 0; i< counter; i++){
        printf("%s\n",argv[1]);
    }
}
