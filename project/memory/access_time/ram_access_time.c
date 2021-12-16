#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <x86intrin.h>
#include <stdint.h>
#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"
int sizes[16] = {32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
int strides[8] = {128, 1024, 4096, 16384, 524288, 1048576, 4194304, 33554432};
void ram_access_time(int currSize, int currStride)
{
    char *arr;
    int SAMPLE_NUM = 1000;
    long double times_for_samples[SAMPLE_NUM];
//    struct test_result res;
    struct Timer timer;
    // get the currSize multiplied by 1024 to get kilobytes amount.
    long numBytes = (currSize * 1024);
    arr = (char *)malloc(numBytes);
    // Put chars into array
    for (long i = 0; i < numBytes; i++)
    {
        arr[i] = (char)rand();
    }
    char temp;
    long index = numBytes-1;
    long total_cycles = 0;
    for (long i = 0; i < SAMPLE_NUM; i++)
    {
        start_timer(&timer);
        temp = arr[index];
        end_timer(&timer);
        // If index is out of bounds then we reset it
        index = index - currStride;
        if (index <= 0)
        {
            index = numBytes-1;
        }
        //Get the difference in the times and add it to a total
        times_for_samples[i] = calc_diff(&timer);
        total_cycles += calc_diff(&timer);

    }
//    printf("Array Size = %d, Stride Size = %d, Average cycles: %d\n", currSize * 1024, currStride, total_cycles/NUM_SAMPLES);
    //Print it out in CSV form.
    printf("%d,%d,%d\n", currSize * 1024, currStride, total_cycles/SAMPLE_NUM);
}
int main()
{
    //Loop through strides and sizes and run for each.
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            ram_access_time(sizes[j], strides[i]);
        }
    }
}
