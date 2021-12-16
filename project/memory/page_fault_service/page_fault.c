#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define PAGESIZE 4096

int main(){

    int count = 0;
    double sum_time = 0;

    while(count < 1000){
        int fd = open("./hello.jpg", O_RDONLY, S_IRUSR | S_IWUSR);
        struct stat sb;

        if (fstat(fd,&sb) == -1){
            perror("Wasn't able to get file size. \n");
        }

    // printf("The file size is %ld\n", sb.st_size);
        
        char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

        clock_t t;
        t = clock();
        u_int8_t *memory = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        t = clock() - t;
        double time = ((double)t)/CLOCKS_PER_SEC; // in microseconds

        // printf("The time is: %ld \n", t);

        sum_time = t + sum_time;

        count++;
    }

    printf("The page fault time is average time is %f", sum_time/1000);
    return 0;
}