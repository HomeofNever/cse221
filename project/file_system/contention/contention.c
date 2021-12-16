#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "../../utils/cpu_cycle_count.h"

#define _GNU_SOURCE
#define __USE_GNU 1

long BLOCK_SIZE = 4096;
long mb = 1024*1024;
long gb = 1024*1024*1024;


double GHz = 2.5;
int toMillisecond = 1000000;

long double contention_read(int fd, long double fileSize, char * buf) {
    struct Timer timer;

    /* set file pos indicator to beginning */
    lseek(fd, 0, SEEK_SET);

    // long double cycles_taken = 0;
    start_timer(&timer);
    for (long double i = 0.0; i < fileSize; i += BLOCK_SIZE) {
        // start_timer(&timer);
        read(fd, buf, BLOCK_SIZE);
        // end_timer(&timer);
        // cycles_taken += calc_diff(&timer);
        // printf("Cycles taken: %Lf\n", cycles_taken);
    }
    end_timer(&timer);
    long double ms_to_read = calc_diff(&timer) / (GHz * toMillisecond);
    
    // double times_read = fileSize / BLOCK_SIZE;
    
    // return cycles_taken/times_read;
    return ms_to_read;
}

int main(int argc, char * argv[]) {

    // if no file passed in exit
    if (argc < 2) {
        printf("No valid file was passed in!");
        return 1;
    }

    char * file_name = argv[1];

    int file = open(file_name, O_RDONLY);

    char * buf = (char *) malloc(sizeof(char)*BLOCK_SIZE);

    //THIS IS FILE SIZE IN BYTES
    long double file_size = 64*mb;
    //This works on MAC but not the machine we are testing for the file cache disabling.
    // if(fcntl(file, F_NOCACHE, 1) == -1) {
    //     printf("Failed to disable file cache.\n");
    // }
    long double ms_to_read = contention_read(file, file_size, buf);

    char output[32];
    FILE * result_file = fopen("contention_res.txt", "a");
    sprintf(output, "%Lf", ms_to_read);
    fprintf(result_file,"%s\n", output);
    fclose(result_file);

    close(file);
    free(buf);

    return 0;
}


