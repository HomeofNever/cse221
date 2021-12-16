#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * fpointer = fopen("/mnt/nfs/remote/hello.txt", "r");

    if(fpointer == NULL){
        perror("Can't open file");
        exit(1);
    }

    char line[100];


    // printf("File to array has started\n");
    int count = 0;
    while(fgets(line, sizeof(line), fpointer)){
        printf("file Found!!");
    }
    return 0;
}