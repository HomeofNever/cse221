#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../utils/cpu_cycle_count.h"

long BUF_SIZE = 65536;
// number of bytes in 1 gb
long gb = 1024*1024*1024;

double GHz = 2.5;
int toMillisecond = 1000000;

long double file_cache_size_read(int fd, long double fileSize, char * buffer) {
    struct Timer timer;
    //Go to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    start_timer(&timer);

    for (long double i = 0.0; i < fileSize; i += BUF_SIZE) {
        read(fd, buffer, BUF_SIZE);
    }

    end_timer(&timer);

    long double cycles_taken = calc_diff(&timer);
    return cycles_taken;
}

int main(void) {

    //Sample and size amount
    int SAMPLES = 16;
    int const SIZES = 40;
    long double averages[SIZES];
    long double timesForCurrFile[SAMPLES];
    //Change this to testFile being used.
    char * file_name = "testFile";

    //Oopen file and populate buffer
    int file = open(file_name, O_RDONLY);
    char * buffer = (char *) malloc(BUF_SIZE*sizeof(char));

    // Go through all the file sizes
    for (int i = 0; i < SIZES; i++) {
        long double fSize = (gb + gb * i) / gb;
        printf("The current size of the file is: %Lf GB.\n", fSize);
        for (int j = 0; j < SAMPLES; j++) {
            long double bytesForFile = gb + gb * i;

            //First time of loading in the data
            file_cache_size_read(file, bytesForFile, buffer);

            //Do a second read now, see if it's fitted into the cache.
            long double time_taken = file_cache_size_read(file, bytesForFile, buffer);

            //Store into the array to calculate average later.
            timesForCurrFile[j] = time_taken;
        }

        long double totaltime = 0;
        for (int i = 0; i < SAMPLES; i++) {
            totaltime += timesForCurrFile[i];
        }
        long double average_cycles = totaltime / SAMPLES;
        printf("Average cycle time is: %Lf\n", average_cycles);

        long double avg_time = average_cycles / (GHz * toMillisecond);
        printf("Average milliseconds: %Lf\n", avg_time);

        averages[i] = avg_time;
    }

    close(file);
    free(buffer);

    return 0;
}